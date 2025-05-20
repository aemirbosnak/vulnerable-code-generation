//FormAI DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    gets(str);

    // Counting the number of vowels and consonants
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'
                || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') 
            vowels++;
        else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
            consonants++;
    }

    printf("Your input: %s\n", str);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    // Reversing the string using pointers
    char* ptr1 = str;
    char* ptr2 = str + strlen(str) - 1;

    while(ptr1 < ptr2) {
        char temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }

    printf("The reversed string: %s\n", str);

    // Removing all vowels from the string
    char new_str[100];
    int j = 0;

    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'
                && str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    printf("The string without vowels: %s\n", new_str);

    return 0;
}