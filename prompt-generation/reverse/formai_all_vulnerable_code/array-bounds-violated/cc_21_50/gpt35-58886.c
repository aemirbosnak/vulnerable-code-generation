//FormAI DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char original_string[100], new_string[100];
    int choice, position, count, length, i, j;
    char substring[100], replace[100];

    printf("Enter the original string: ");
    fgets(original_string, sizeof(original_string), stdin);
    length = strlen(original_string)-1;

    do {
        printf("Choose the operation you want to perform:\n");
        printf("1. Find a substring in the string.\n");
        printf("2. Replace a substring with another string in the string.\n");
        printf("3. Convert the string to uppercase.\n");
        printf("4. Convert the string to lowercase.\n");
        printf("5. Reverse the string.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {

            case 1: // Find a substring
                printf("Enter the substring you want to find: ");
                fgets(substring, sizeof(substring), stdin);
                count = 0;

                for(i=0; i<length; i++) {
                    if(original_string[i] == substring[0]) {
                        for(j=1; j<strlen(substring)-1; j++) {
                            if(original_string[i+j] != substring[j]) {
                                break;
                            }
                        }
                        if(j==strlen(substring)-1) {
                            count++;
                        }
                    }
                }

                if(count == 0) {
                    printf("Substring not found.\n");
                } else {
                    printf("'%s' occurs %d times in the string.\n", substring, count);
                }
                break;

            case 2: // Replace a substring
                printf("Enter the substring you want to replace: ");
                fgets(substring, sizeof(substring), stdin);
                printf("Enter the string you want to replace it with: ");
                fgets(replace, sizeof(replace), stdin);

                i=0;
                while(i<length) {
                    if(original_string[i] == substring[0]) {
                        for(j=1; j<strlen(substring)-1; j++) {
                            if(original_string[i+j] != substring[j]) {
                                break;
                            }
                        }
                        if(j==strlen(substring)-1) { // substring found
                            if(strlen(replace) < strlen(substring)) { // if replace string is shorter than substring, shift the remaining characters to left
                                for(int k=i+strlen(substring); k<length+strlen(replace)-strlen(substring); k++) {
                                    original_string[k] = original_string[k+strlen(replace)-strlen(substring)];
                                }
                                length = length + strlen(replace) - strlen(substring);
                                original_string[length] = '\0';
                            } else if(strlen(replace) > strlen(substring)) { // if replace string is longer than substring, shift the remaining characters to right
                                for(int k=length+strlen(replace)-strlen(substring); k>=i+strlen(replace); k--) {
                                    original_string[k] = original_string[k-strlen(replace)+strlen(substring)];
                                }
                                length = length + strlen(replace) - strlen(substring);
                                original_string[length] = '\0';
                            }
                            // Replace substring with replace string
                            for(int k=0; k<strlen(replace); k++) {
                                original_string[i+k] = replace[k];
                            }
                            i = i + strlen(replace); // continue from end of replace string
                        } else {
                            i++;
                        }
                    } else {
                        i++;
                    }
                }
                printf("After replacing '%s' with '%s', the modified string is: %s\n", substring, replace, original_string);
                break;

            case 3: // Convert to uppercase
                for(i=0; i<length; i++) {
                    if(original_string[i] >= 'a' && original_string[i] <= 'z') {
                        new_string[i] = original_string[i] - ('a' - 'A');
                    } else {
                        new_string[i] = original_string[i];
                    }
                }
                new_string[length] = '\0';
                printf("The uppercase string is: %s\n", new_string);
                break;

            case 4: // Convert to lowercase
                for(i=0; i<length; i++) {
                    if(original_string[i] >= 'A' && original_string[i] <= 'Z') {
                        new_string[i] = original_string[i] + ('a' - 'A');
                    } else {
                        new_string[i] = original_string[i];
                    }
                }
                new_string[length] = '\0';
                printf("The lowercase string is: %s\n", new_string);
                break;

            case 5: // Reverse the string
                for(i=length-1, j=0; i>=0; i--, j++) {
                    new_string[j] = original_string[i];
                }
                new_string[length] = '\0';
                printf("The reversed string is: %s\n", new_string);
                break;

            case 6: // Exit
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}