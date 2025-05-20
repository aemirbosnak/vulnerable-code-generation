//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void async_reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
        printf("%s\n", str);
    }
}

int main() {
    char original_str[100], thread_str[100];
    int start, end, choice;
    printf("Enter a string: ");
    fgets(original_str, 100, stdin);
    
    do {
        printf("\n\n1. Reverse a string\n2. Async reverse a string\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume \n character from input buffer
        switch (choice) {
            case 1:
                // reverse original string non-asynchronously
                start = 0;
                end = strlen(original_str) - 2;
                reverse_string(original_str, start, end);
                printf("Reversed string: %s\n", original_str);
                break;
            case 2:
                // copy original string to a new string
                strcpy(thread_str, original_str);
                // reverse copy asynchronously in a separate thread
                start = 0;
                end = strlen(thread_str) - 2;
                async_reverse_string(thread_str, start, end);
                break;
            case 3:
                // quit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}