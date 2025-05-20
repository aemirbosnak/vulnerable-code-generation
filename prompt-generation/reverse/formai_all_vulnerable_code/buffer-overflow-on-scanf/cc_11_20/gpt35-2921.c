//FormAI DATASET v1.0 Category: Digital Diary ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[50], password[50];
    printf("Welcome to your Digital Diary!\n\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    int loginFailed = 0;
    if (strcmp(username, "puzzle") != 0 || strcmp(password, "2021") != 0) {
        loginFailed = 1;
    }

    if (loginFailed) {
        printf("\nAccess denied!\n");
        return 0;
    }

    printf("\nWelcome, %s!\n", username);
    printf("\nWhat would you like to do today?\n");

    int choice;
    do {
        printf("\n1. Add new entry.\n");
        printf("2. View all entries.\n");
        printf("3. Exit.\n\n");
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdding new entry:\n");
                printf("Please enter the date (DD/MM/YYYY): ");
                char date[11];
                scanf("%s", date);
                printf("Please enter the time (HH:MM): ");
                char time[6];
                scanf("%s", time);
                printf("Please enter your entry:\n");
                char entry[500];
                getchar();
                fgets(entry, 500, stdin);

                FILE *file = fopen("diary.txt", "a");
                if (file) {
                    fprintf(file, "Date: %s\n", date);
                    fprintf(file, "Time: %s\n", time);
                    fprintf(file, "Entry: %s\n\n", entry);
                    printf("\nEntry added successfully!\n");
                    fclose(file);
                } else {
                    printf("\nError opening file. Entry not added.\n");
                }
                break;

            case 2:
                {
                    FILE *file = fopen("diary.txt", "r");
                    if (file) {
                        char line[1000];
                        while (fgets(line, 1000, file)) {
                            printf("%s", line);
                        }
                        fclose(file);
                    } else {
                        printf("\nYou haven't added any entries yet.\n");
                    }
                }
                break;

            case 3:
                printf("\nExiting...\n");
                return 0;
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}