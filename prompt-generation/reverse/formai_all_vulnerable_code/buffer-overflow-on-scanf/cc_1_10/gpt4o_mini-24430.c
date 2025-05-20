//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void capitalizeFirstLetter(char *str) {
    if (str[0] != '\0') {
        str[0] = toupper(str[0]);
        for (int i = 1; str[i]; i++) {
            str[i] = tolower(str[i]);
        }
    }
}

void alternateCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (i % 2 == 0) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void displayMenu() {
    printf("\nShape-Shifting String Manipulation Menu\n");
    printf("1. Reverse the String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Capitalize First Letter\n");
    printf("5. Alternate Case\n");
    printf("6. Combine Options\n");
    printf("7. Exit\n");
}

int main() {
    char str[256];
    int choice, running = 1;

    printf("Enter a string (max 255 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove trailing newline

    while (running) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after scanf

        switch (choice) {
            case 1:
                reverseString(str);
                printf("Reversed String: %s\n", str);
                break;
            case 2:
                toUpperCase(str);
                printf("Uppercase String: %s\n", str);
                break;
            case 3:
                toLowerCase(str);
                printf("Lowercase String: %s\n", str);
                break;
            case 4:
                capitalizeFirstLetter(str);
                printf("Capitalized String: %s\n", str);
                break;
            case 5:
                alternateCase(str);
                printf("Alternating Case String: %s\n", str);
                break;
            case 6: {
                char temp[256];
                strcpy(temp, str); // Copy original string

                printf("Now, combine transformations!\n");
                printf("Enter new string: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0'; 

                printf("Choose transformations (1-5) separated by spaces: " );
                int options[5];
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &options[i]);
                }
                getchar(); // Clear newline character after scanf

                for (int i = 0; i < 5; i++) {
                    int opt = options[i];
                    switch (opt) {
                        case 1:
                            reverseString(temp);
                            break;
                        case 2:
                            toUpperCase(temp);
                            break;
                        case 3:
                            toLowerCase(temp);
                            break;
                        case 4:
                            capitalizeFirstLetter(temp);
                            break;
                        case 5:
                            alternateCase(temp);
                            break;
                    }
                }
                printf("Final Transformed String: %s\n", temp);
                break;
            }
            case 7:
                running = 0;
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}