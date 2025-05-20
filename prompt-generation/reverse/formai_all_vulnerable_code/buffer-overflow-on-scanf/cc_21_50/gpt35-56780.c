//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int choice1, choice2, i, j;
    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    do {
        printf("\nSelect a text transformation option:\n");
        printf("1. Uppercase\n");
        printf("2. Lowercase\n");
        printf("3. Titlecase\n");
        printf("4. Reverse\n");
        printf("5. Shuffling\n");
        printf("6. Exit\n");

        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                for (i = 0; i < strlen(text); i++) {
                    if (text[i] >= 'a' && text[i] <= 'z') {
                        text[i] = text[i] - 32;
                    }
                }
                printf("Uppercase text: %s", text);
                break;

            case 2:
                for (i = 0; i < strlen(text); i++) {
                    if (text[i] >= 'A' && text[i] <= 'Z') {
                        text[i] = text[i] + 32;
                    }
                }
                printf("Lowercase text: %s", text);
                break;

            case 3:
                for (i = 0; i < strlen(text); i++) {
                    if (i == 0 || text[i - 1] == ' ' && text[i] >= 'a' && text[i] <= 'z') {
                        text[i] = text[i] - 32;
                    }
                }
                printf("Titlecase text: %s", text);
                break;

            case 4:
                for (i = strlen(text)-1; i >= 0; i--) {
                    printf("%c", text[i]);
                }
                break;

            case 5:
                printf("Select a shuffling option:\n");
                printf("1. Random shuffle\n");
                printf("2. Reverse shuffle\n");
                scanf("%d", &choice2);

                switch (choice2) {
                    case 1:
                        for (i = 0; i < strlen(text); i++) {
                            j = rand() % strlen(text);
                            char temp = text[i];
                            text[i] = text[j];
                            text[j] = temp;
                        }
                        printf("Random shuffle text: %s", text);
                        break;

                    case 2:
                        for (i = 0; i < strlen(text)/2; i++) {
                            char temp = text[i];
                            text[i] = text[strlen(text)-i-1];
                            text[strlen(text)-i-1] = temp;
                        }
                        printf("Reverse shuffle text: %s", text);
                        break;

                    default:
                        printf("Invalid shuffling option.\n");
                        break;
                }
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice1 != 6);

    return 0;
}