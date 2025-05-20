//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char date[20];
    char time[10];
    char content[500];
};

int main() {
    struct entry diary[365];
    int option;
    int count = 0;
    char filename[20];
    FILE *file;

    printf("*** Welcome to My Digital Diary! ***\n");

    while (1) {
        printf("\nEnter your option: ");
        printf("\n1. Write Entry\n2. View Entry\n3. Exit\n");
        scanf("%d", &option);

        if (option == 1) {
            time_t rawTime;
            struct tm *time_info;
            time(&rawTime);
            time_info = localtime(&rawTime);

            strftime(diary[count].date, 20, "%x", time_info);
            strftime(diary[count].time, 20, "%I:%M %p", time_info);

            printf("\nEnter your content (max 500 characters):\n");
            fflush(stdin);
            fgets(diary[count].content, 500, stdin);
            
            count++;

            printf("\nEntry Saved Successfully!\n");
        }

        else if (option == 2) {
            int entry_num;

            printf("\nEnter Entry Number: ");
            scanf("%d", &entry_num);

            if (entry_num <= count) {
                printf("\nDate: %s\nTime: %s\nContent: %s", diary[entry_num-1].date, diary[entry_num-1].time, diary[entry_num-1].content);
            }
            else {
                printf("\nInvalid Entry Number.\n");
            }
        }

        else if (option == 3) {
            printf("\nEnter Filename to Save Diary (max 20 characters): ");
            fflush(stdin);
            fgets(filename, 20, stdin);
            filename[strlen(filename) - 1] = '\0';

            strcat(filename, ".txt");

            file = fopen(filename, "w");

            if (file == NULL) {
                printf("\nError Opening File.\n");
                exit(0);
            }

            for (int i = 0; i < count; i++) {
                fprintf(file, "Date: %s\n", diary[i].date);
                fprintf(file, "Time: %s\n", diary[i].time);
                fprintf(file, "Content: %s\n\n", diary[i].content);
            }

            fclose(file);

            printf("\nDiary Saved Successfully in %s file!\n", filename);
            break;
        }

        else {
            printf("\nInvalid Option!\n");
        }
    }

    return 0;
}