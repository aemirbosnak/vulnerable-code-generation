//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to remove all special characters and digits from string
void removeSpecialChar(char *str) {
    int i, j;
    for(i=0, j=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

//Function to reverse a string
void reverseString(char *str) {
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//Function to count number of vowels in string
int countVowels(char *str) {
    int i, count=0;
    for(i=0; str[i]!='\0'; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    //Removing special characters and digits
    printf("\nString after removing special characters and digits: ");
    removeSpecialChar(str);
    printf("%s\n", str);

    //Reversing string
    printf("\nReversed string: ");
    reverseString(str);
    printf("%s\n", str);

    //Counting number of vowels
    printf("\nNumber of vowels in string: %d", countVowels(str));

    return 0;
}