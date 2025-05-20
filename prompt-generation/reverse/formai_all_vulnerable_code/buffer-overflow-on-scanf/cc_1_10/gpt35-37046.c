//FormAI DATASET v1.0 Category: String manipulation ; Style: protected
#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 100

void reverseString(char *s, int start, int end) {
    while(start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void swapChar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void capitalizeString(char *s) {
    int i = 0;
    while(s[i]) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        i++;
    }
}

void toggleString(char *s) {
    int i = 0;
    while(s[i]) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

void removeChar(char *s, char c) {
    int i = 0, j = 0;
    while(s[j]) {
        if(s[j] != c) {
            s[i] = s[j];
            i++;
        } 
        j++;
    }
    s[i] = '\0';
}

void removeDuplicates(char *s) {
    int i, j, k;
    int n = strlen(s);
    if(n < 2) return;
 
    for(i = 0; i < n; ++i) {
        if(s[i]) {
            s[j++] = s[i];
            for(k = i+1; k < n; ++k) {
                if(s[k] == s[i]) {
                    s[k] = 0;
                }
            }
        }
    }
    s[j] = '\0';
}

int main() {
    char str[MAX_LENGTH];
    int choice;
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0; // To remove the newline character added by fgets

    do {
        printf("\nChoose an operation to perform:\n\n");
        printf("1. Reverse the string\n");
        printf("2. Capitalize the string\n");
        printf("3. Toggle case of the string\n");
        printf("4. Remove a particular character from the string\n");
        printf("5. Remove duplicates from the string\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int n = strlen(str);
                reverseString(str, 0, n-1);
                printf("\nReversed string: %s\n", str);
                break;
            }
            case 2: {
                capitalizeString(str);
                printf("\nCapitalized string: %s\n", str);
                break;
            }
            case 3: {
                toggleString(str);
                printf("\nToggled string: %s\n", str);
                break;
            }
            case 4: {
                char c;
                printf("\nEnter the character to remove: ");
                scanf(" %c", &c);
                removeChar(str, c);
                printf("\nString after removing %c: %s\n", c, str);
                break;
            }
            case 5: {
                removeDuplicates(str);
                printf("\nString after removing duplicates: %s\n", str);
                break;
            }
            case 6: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 6);

    return 0;
}