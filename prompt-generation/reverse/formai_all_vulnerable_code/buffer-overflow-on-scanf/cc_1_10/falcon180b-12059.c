//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    FILE *diary_file;
    char filename[50];
    time_t now;
    struct tm *tm_now;

    srand(time(NULL));
    now = time(NULL);
    tm_now = localtime(&now);
    strftime(filename, 50, "diary_%Y%m%d_%H%M%S.txt", tm_now);
    diary_file = fopen(filename, "w");

    if (diary_file == NULL) {
        printf("Error: could not create diary file.\n");
        return 1;
    }

    printf("Welcome to your digital diary!\n");
    printf("Press 'n' for a new entry,'s' to save, 'q' to quit.\n");

    while (1) {
        char choice;
        scanf("%c", &choice);

        switch (choice) {
        case 'n':
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full.\n");
            } else {
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", diary[num_entries].date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", diary[num_entries].time);
                printf("Enter content:\n");
                fgets(diary[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
            }
            break;
        case's':
            for (int i = 0; i < num_entries; i++) {
                fprintf(diary_file, "%s %s\n%s\n\n", diary[i].date, diary[i].time, diary[i].content);
            }
            fclose(diary_file);
            printf("Diary saved to file.\n");
            break;
        case 'q':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}