//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to My Digital Diary!\n");

    int option;
    char date[100];
    char entry[1000];

    while(1) {
        printf("Please select an option:\n1. New Entry\n2. View Entry\n3. Quit\n"); 
        scanf("%d", &option);

        if(option == 1) {
            FILE *fp;
            fp = fopen("diary.txt", "a");

            printf("Enter the date (format: DD/MM/YYYY): ");
            scanf("%s", date);

            printf("Type your entry below:\n");
            scanf(" %[^\n]s", entry);

            time_t seconds;
            seconds = time(NULL);
            char *timestamp = ctime(&seconds);

            fprintf(fp, "Date: %s\n%s\n%s\n\n", date, timestamp, entry);
            fclose(fp);

            printf("\nEntry added successfully!\n\n");
        }
        else if(option == 2) {
            FILE *fp;

            fp = fopen("diary.txt", "r");
            if(fp == NULL) {
                printf("No entries found.\n");
                continue;
            }

            char line[1000];

            printf("\n\n");
            while(fgets(line, 1000, fp)) {
                printf("%s", line);
            }
            printf("\n\n");

            fclose(fp);
        }
        else if(option == 3) {
            printf("Goodbye! Thank you for using My Digital Diary.\n");
            break;
        }
        else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}