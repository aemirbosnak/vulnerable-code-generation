//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct password {
    char site[100];
    char username[100];
    char password[100];
};

int main() {
    int choice = 0;
    struct password p;

    printf("Welcome to Password Manager!\n");
    printf("-----------------------------\n\n");

    do {
        printf("Please select one of the following options:\n");
        printf("1. Add a new password\n");
        printf("2. View existing passwords\n");
        printf("3. Quit the program\n\n");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("\nAdding a new password...\n");
                printf("Please enter the site name: ");
                fgets(p.site, sizeof(p.site), stdin);
                p.site[strcspn(p.site, "\n")] = 0;

                printf("Please enter the username: ");
                fgets(p.username, sizeof(p.username), stdin);
                p.username[strcspn(p.username, "\n")] = 0;

                printf("Please enter the password: ");
                fgets(p.password, sizeof(p.password), stdin);
                p.password[strcspn(p.password, "\n")] = 0;

                printf("\nYour password for %s has been saved!\n\n", p.site);

                // save password to file
                FILE *file;
                file = fopen("passwords.txt", "a");
                fprintf(file, "%s %s %s\n", p.site, p.username, p.password);
                fclose(file);

                break;

            case 2:
                printf("\nViewing existing passwords...\n");

                // read passwords from file and print them out
                file = fopen("passwords.txt", "r");
                if (file) {
                    printf("\nSite\t\tUsername\tPassword\n");
                    printf("--------------------------------------------------\n");

                    while(fscanf(file, "%s %s %s", p.site, p.username, p.password) != EOF) {
                        printf("%s\t\t%s\t\t%s\n", p.site, p.username, p.password);
                    }

                    printf("\n");
                    fclose(file);
                } else {
                    printf("\nNo passwords have been saved yet.\n\n");
                }

                break;

            case 3:
                printf("\nThank you for using Password Manager!\n");
                break;

            default:
                printf("\nInvalid option selected. Please try again.\n\n");
                break;
        }

    } while (choice != 3);

    return 0;
}