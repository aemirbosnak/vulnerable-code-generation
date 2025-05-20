//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void to_upper_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}

void to_lower_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

void reverse_string(char *str, char *result) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        result[i] = str[length - 1 - i];
    }
    result[length] = '\0'; // Null-terminate the reversed string
}

void find_and_replace(char *str, const char *target, const char *replacement) {
    char *pos, temp[MAX_LENGTH];
    int index = 0;
    int target_length = strlen(target);
    int replacement_length = strlen(replacement);

    while ((pos = strstr(str + index, target)) != NULL) {
        // Copying str till the target occurence
        strncpy(temp, str + index, pos - (str + index));
        temp[pos - (str + index)] = '\0';
        
        // Appending replacement
        strcat(temp, replacement);
        
        // Appending the rest of the string after the target
        strcat(temp, pos + target_length);
        
        // Updating str
        strcpy(str, temp);
        
        // Update index for further searching in the modified string
        index = pos - str + replacement_length;
    }
}

void display_menu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Convert to Upper Case\n");
    printf("2. Convert to Lower Case\n");
    printf("3. Reverse the String\n");
    printf("4. Find and Replace\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char str[MAX_LENGTH];
    char result[MAX_LENGTH];
    char target[MAX_LENGTH], replacement[MAX_LENGTH];
    int choice;

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the newline character

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer

        switch (choice) {
            case 1:
                to_upper_case(str);
                printf("Upper case: %s\n", str);
                break;
            case 2:
                to_lower_case(str);
                printf("Lower case: %s\n", str);
                break;
            case 3:
                reverse_string(str, result);
                printf("Reversed string: %s\n", result);
                break;
            case 4:
                printf("Enter target substring: ");
                fgets(target, MAX_LENGTH, stdin);
                target[strcspn(target, "\n")] = 0; // Remove newline
                printf("Enter replacement substring: ");
                fgets(replacement, MAX_LENGTH, stdin);
                replacement[strcspn(replacement, "\n")] = 0; // Remove newline
                find_and_replace(str, target, replacement);
                printf("Modified string: %s\n", str);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    return 0;
}