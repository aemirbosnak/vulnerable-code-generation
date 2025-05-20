//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: brave
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void reverse(char str[]);
void capitalize(char str[]);
void removeSpaces(char str[]);
void replaceChars(char str[], char from, char to);
void countChars(char str[], char ch);

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("\nOriginal string: %s\n", str);
    reverse(str);
    printf("Reversed string: %s\n", str);
    capitalize(str);
    printf("Capitalized string: %s\n", str);
    removeSpaces(str);
    printf("String without spaces: %s\n", str);
    replaceChars(str, 'a', 'b');
    printf("String with 'a' replaced by 'b': %s\n", str);
    countChars(str, 'a');

    return 0;
}

void reverse(char str[]) {
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void capitalize(char str[]) {
    int i;
    for(i=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeSpaces(char str[]) {
    int i, j;
    for(i=0, j=0; str[i]!='\0'; i++) {
        if(str[i]!=' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void replaceChars(char str[], char from, char to) {
    int i;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]==from) {
            str[i] = to;
        }
    }
}

void countChars(char str[], char ch) {
    int count = 0;
    int i;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]==ch) {
            count++;
        }
    }
    printf("Number of '%c's in the string: %d\n", ch, count);
}