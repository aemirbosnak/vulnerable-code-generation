//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main() {
    // Declare and initialize variables
    char str[MAX_STR_LEN];
    char temp[MAX_STR_LEN];
    char search[MAX_STR_LEN];
    char replace[MAX_STR_LEN];
    int menuChoice;
    
    printf("*** Welcome to the String Manipulation Program ***\n\n");
    
    // Prompt user to enter string
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    
    // Remove trailing newline character from string
    str[strcspn(str, "\n")] = '\0';
    
    // Display menu options to user
    printf("\n Choose from the following menu options: \n");
    printf("1. Reverse the string\n");
    printf("2. Convert string to uppercase\n");
    printf("3. Convert string to lowercase\n");
    printf("4. Find and replace a substring\n");
    printf("5. Exit program\n");
    
    // Prompt user to select menu option
    printf("\nYour option: ");
    scanf("%d", &menuChoice);
    
    // Perform desired operation based on user selection
    switch(menuChoice) {
        case 1:
            // Reverse the string
            for(int i = strlen(str)-1; i >= 0; i--) {
                printf("%c", str[i]);
            }
            break;
        case 2:
            // Convert string to uppercase
            for(int i = 0; i < strlen(str); i++) {
                printf("%c", toupper(str[i]));
            }
            break;
        case 3:
            // Convert string to lowercase
            for(int i = 0; i < strlen(str); i++) {
                printf("%c", tolower(str[i]));
            }
            break;
        case 4:
            // Find and replace substring
            printf("Enter the substring to search for: ");
            scanf("%s", search);
            
            printf("Enter the substring to replace with: ");
            scanf("%s", replace);
            
            char *ptr = strstr(str, search);
            if(ptr != NULL) {
                strncpy(temp, str, ptr-str);
                temp[ptr-str] = '\0';
                strcat(temp, replace);
                strcat(temp, ptr+strlen(search));
                printf("Result: %s\n", temp);
            }
            else {
                printf("Substring not found\n");
            }
            break;
        case 5:
            // Exit program
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid option selected\n");
    }
    
    return 0;
}