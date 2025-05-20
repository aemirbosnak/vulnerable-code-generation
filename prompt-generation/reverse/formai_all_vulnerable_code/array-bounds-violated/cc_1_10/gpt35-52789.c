//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char website[100] = "";
    char option[10] = "";
    int i;

    printf("Welcome to the Surrealist C Browser Plugin Example Program!\n\n");
    printf("Please enter a website URL: ");
    fgets(website, 100, stdin);

    // Remove newline character from website string
    website[strlen(website) - 1] = '\0';

    printf("\n1. Add random words to website\n");
    printf("2. Rearrange letters of website\n");
    printf("3. Change case of website\n");
    printf("4. Exit program\n\n");
    printf("Please choose an option (1-4): ");
    fgets(option, 10, stdin);

    // Remove newline character from option string
    option[strlen(option) - 1] = '\0';

    switch (atoi(option)) {
        case 1:
            for (i = strlen(website) - 1; i >= 0; i--) {
                int j;
                for (j = rand() % 5; j >= 0; j--) {
                    printf("%c", (rand() % 26) + 'a');
                }
                printf("%c", website[i]);
                printf(" ");
            }
            printf("\n");
            break;
        case 2:
            for (i = strlen(website) - 1; i >= 0; i--) {
                printf("%c", website[rand() % strlen(website)]);
            }
            printf("\n");
            break;
        case 3:
            for (i = 0; i < strlen(website); i++) {
                if (isupper(website[i])) {
                    printf("%c", tolower(website[i]));
                } else {
                    printf("%c", toupper(website[i]));
                }
            }
            printf("\n");
            break;
        case 4:
            printf("Thank you for using this program!\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
    }

    return 0;
}