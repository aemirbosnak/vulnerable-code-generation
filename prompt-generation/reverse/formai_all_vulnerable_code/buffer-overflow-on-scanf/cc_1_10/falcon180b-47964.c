//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    int count = 0;
    char filename[50];
    time_t now;
    struct tm *tm;
    struct entry entries[MAX_ENTRIES];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    time(&now);
    tm = localtime(&now);
    strftime(entries[count].date, 20, "%Y-%m-%d", tm);
    strftime(entries[count].time, 20, "%H:%M:%S", tm);

    while (count < MAX_ENTRIES && fgets(entries[count].content, MAX_ENTRY_LENGTH, stdin)!= NULL) {
        count++;
    }

    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(filename, 50, fp)!= NULL) {
        if (strcmp(filename, "END OF FILE") == 0) {
            break;
        }

        tm = NULL;
        strptime(filename, "%Y-%m-%d %H:%M:%S", &tm);
        printf("%s %s\n", asctime(tm), entries[count - 1].content);

        count--;
    }

    fclose(fp);

    return 0;
}