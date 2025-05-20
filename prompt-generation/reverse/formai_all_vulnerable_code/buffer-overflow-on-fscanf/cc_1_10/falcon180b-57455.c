//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *fp;
    char filename[50] = "diary.txt";
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    time_t current_time;
    struct tm *time_info;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist. Creating new file.\n");
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Error creating file.\n");
            exit(1);
        }
        fclose(fp);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }
    }

    while (fscanf(fp, "%s %s %s", diary[num_entries].date, diary[num_entries].time, diary[num_entries].content)!= EOF) {
        num_entries++;
    }

    fclose(fp);

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", time_info);
    strftime(diary[num_entries].time, 20, "%H:%M:%S", time_info);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "%s %s %s\n", diary[num_entries].date, diary[num_entries].time, diary[num_entries].content);

    fclose(fp);

    return 0;
}