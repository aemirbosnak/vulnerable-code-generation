//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char str[MAX_STRING_LENGTH], sub_str[MAX_STRING_LENGTH], new_str[MAX_STRING_LENGTH];
    int op;

    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("You entered: %s\n", str);

    printf("What operation would you like to perform?\n");
    printf("1. Find length\n");
    printf("2. Reverse string\n");
    printf("3. Copy string\n");
    printf("4. Concatenate string\n");
    printf("5. Find substring\n");
    printf("6. Replace substring\n");
    printf("Enter your choice: ");
    scanf("%d", &op);

    switch(op) {
        case 1: // Find length
            printf("String length: %ld\n", strlen(str));
            break;
        case 2: // Reverse string
            for (int i = strlen(str) - 1; i >= 0; i--) {
                printf("%c", str[i]);
            }
            printf("\n");
            break;
        case 3: // Copy string
            strcpy(new_str, str);
            printf("New string: %s\n", new_str);
            break;
        case 4: // Concatenate string
            printf("Enter string to concatenate: ");
            scanf("%s", new_str);
            strcat(str, new_str);
            printf("New string: %s\n", str);
            break;
        case 5: // Find substring
            printf("Enter substring to find: ");
            scanf("%s", sub_str);
            if (strstr(str, sub_str) != NULL) {
                printf("Substring found!\n");
            } else {
                printf("Substring not found!\n");
            }
            break;
        case 6: // Replace substring
            printf("Enter substring to replace: ");
            scanf("%s", sub_str);
            printf("Enter new substring: ");
            scanf("%s", new_str);
            char *ptr = strstr(str, sub_str);
            if (ptr != NULL) {
                char temp[MAX_STRING_LENGTH];
                strncpy(temp, str, ptr - str);
                temp[ptr - str] = '\0';
                strcat(temp, new_str);
                ptr += strlen(sub_str);
                strcat(temp, ptr);
                strcpy(str, temp);
                printf("New string: %s\n", str);
            } else {
                printf("Substring not found!\n");
            }
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}