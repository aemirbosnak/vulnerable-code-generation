//FormAI DATASET v1.0 Category: File handling ; Style: Ada Lovelace
/* ================================================
File Handling Example Program using C Language
By: Ada Lovelace

This program demonstrates how to read and write data
into a file using C language.

Note: This program requires a text file called "data.txt"
to exist in the same directory as the executable file.

=================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    FILE *fp;
    char name[MAX_LENGTH], address[MAX_LENGTH], phone[MAX_LENGTH];
    int option;

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add new record\n");
        printf("2. View existing records\n");
        printf("3. Exit\n");

        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                fp = fopen("data.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                printf("\nEnter name: ");
                fgets(name, MAX_LENGTH, stdin);

                printf("Enter address: ");
                fgets(address, MAX_LENGTH, stdin);

                printf("Enter phone number: ");
                fgets(phone, MAX_LENGTH, stdin);

                fprintf(fp, "%s, %s, %s\n", name, address, phone);
                printf("\nNew data added successfully!\n");

                fclose(fp);
                break;

            case 2:
                fp = fopen("data.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                printf("\nExisting records:\n");
                printf("-----------------\n");

                char line[MAX_LENGTH];
                while (fgets(line, MAX_LENGTH, fp) != NULL) {
                    printf("%s", line);
                }
                printf("-----------------\n");

                fclose(fp);
                break;

            case 3:
                printf("Exiting program...");
                exit(0);
                break;

            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    }

    return 0;
}