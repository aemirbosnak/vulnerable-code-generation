//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

void reverseString(char* str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start+1, end-1);
}

void concatenateString(char* dest, char* src) {
    if (*dest == '\0') {
        strcpy(dest, src);
        return;
    }
    concatenateString(dest+1, src);
}

int countWord(char* str, int index, int count) {
    if (str[index] == '\0') {
        return count;
    }
    if (str[index] != ' ' && (index == 0 || str[index-1] == ' ')) {
        count++;
    }
    return countWord(str, index+1, count);
}

int main() {
    int choice;
    char str[100], temp[100];

    do {
        printf("\n\n1. Reverse String\n2. Concatenate String\n3. Count number of words in a string\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);
                reverseString(str, 0, strlen(str)-1);
                printf("Reversed string: %s", str);
                break;
            case 2:
                printf("Enter the destination string: ");
                scanf(" %[^\n]s", str);
                printf("Enter the source string: ");
                scanf(" %[^\n]s", temp);
                concatenateString(str, temp);
                printf("Concatenated string: %s", str);
                break;
            case 3:
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);
                int count = countWord(str, 0, 0);
                printf("Number of words in the string: %d", count);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    } while (choice != 4);

    return 0;
}