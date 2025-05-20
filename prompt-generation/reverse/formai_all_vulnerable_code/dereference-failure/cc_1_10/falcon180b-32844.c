//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *tm_struct;
    char *date_str;
    int month, day, year;
    int hour, minute, second;
    FILE *file_ptr;
    char filename[20];
    char line[100];
    char *token;

    time(&now);

    tm_struct = localtime(&now);

    month = tm_struct->tm_mon + 1;
    day = tm_struct->tm_mday;
    year = tm_struct->tm_year + 1900;

    hour = tm_struct->tm_hour;
    minute = tm_struct->tm_min;
    second = tm_struct->tm_sec;

    date_str = asctime(tm_struct);

    printf("Current Date and Time: %s\n", date_str);

    sprintf(filename, "diary_%d_%d_%d.txt", month, day, year);

    file_ptr = fopen(filename, "a");

    if (file_ptr == NULL) {
        printf("File does not exist. Creating new file.\n");
        file_ptr = fopen(filename, "w");
        fprintf(file_ptr, "Welcome to my digital diary.\n\n");
    } else {
        rewind(file_ptr);
        while (fgets(line, sizeof(line), file_ptr)!= NULL) {
            if (strstr(line, "Date:")!= NULL) {
                printf("Previous entry found.\n");
                fclose(file_ptr);
                return 0;
            }
        }
    }

    fprintf(file_ptr, "Date: %d/%d/%d\n", month, day, year);
    fprintf(file_ptr, "Time: %d:%d:%d\n\n", hour, minute, second);

    printf("Enter your diary entry:\n");
    fgets(line, sizeof(line), stdin);

    fprintf(file_ptr, "%s", line);

    fclose(file_ptr);

    printf("Diary entry saved.\n");

    return 0;
}