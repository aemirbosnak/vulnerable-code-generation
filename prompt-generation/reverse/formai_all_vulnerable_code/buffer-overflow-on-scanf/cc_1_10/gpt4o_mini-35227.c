//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void createString(char **str);
void displayString(const char *str);
void modifyString(char *str);
void analyzeString(const char *str);
void destroyString(char *str);

int main() {
    char *myString = NULL;
    int choice;

    while (1) {
        printf("\nString Manipulation Menu:\n");
        printf("1. Create a String\n");
        printf("2. Display the String\n");
        printf("3. Modify the String\n");
        printf("4. Analyze the String\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                createString(&myString);
                break;
            case 2:
                displayString(myString);
                break;
            case 3:
                modifyString(myString);
                break;
            case 4:
                analyzeString(myString);
                break;
            case 5:
                destroyString(myString);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createString(char **str) {
    char buffer[256];
    printf("Enter the string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character

    *str = malloc(strlen(buffer) + 1);
    if (*str == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    strcpy(*str, buffer);
    printf("String created successfully!\n");
}

void displayString(const char *str) {
    if (str == NULL) {
        printf("No string available to display.\n");
        return;
    }
    printf("The current string is: %s\n", str);
}

void modifyString(char *str) {
    if (str == NULL) {
        printf("No string available to modify.\n");
        return;
    }
    printf("Enter the new string: ");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character

    // Modify the existing string
    free(str);
    str = malloc(strlen(buffer) + 1);
    if (str == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }
    strcpy(str, buffer);
    printf("String modified successfully!\n");
}

void analyzeString(const char *str) {
    if (str == NULL) {
        printf("No string available for analysis.\n");
        return;
    }
    printf("Analyzing the string...\n");
    printf("Length of the string: %lu\n", strlen(str));
    printf("Number of vowels: ");
    
    int vowels = 0;
    for (const char *p = str; *p != '\0'; ++p) {
        char c = tolower(*p);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }
    printf("%d\n", vowels);
}

void destroyString(char *str) {
    if (str != NULL) {
        free(str);
    }
    printf("String memory released.\n");
}