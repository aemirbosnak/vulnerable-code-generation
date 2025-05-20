//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {

    char name[50];
    printf("What is your name?\n");
    scanf("%s", name);

    // Reverse the name
    for(int i = 0, j = strlen(name)-1; i < j; i++, j--) {
        char temp = name[i];
        name[i] = name[j];
        name[j] = temp;
    }

    printf("Hello, ");
    for(int i = 0; i < strlen(name); i++) {

        // Change every other letter to uppercase
        if(i % 2 == 0) {
            printf("%c",toupper(name[i]));
        } else {
            printf("%c",name[i]);
        }
        
        // Add a dash after every 3rd letter
        if(i % 3 == 2 && i != strlen(name)-1) {
            printf("-");
        }
    }
    printf("!\n");

    // Remove all vowels
    char noVowels[50];
    int count = 0;
    for(int i = 0; i < strlen(name); i++) {
        char c = name[i];
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' 
            && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
                noVowels[count] = c;
                count++;
        }
    }
    noVowels[count] = '\0';

    printf("Without vowels: %s\n", noVowels);

    return 0;
}