//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include<stdio.h>
#include<string.h>

int main(){
    printf("Welcome to Curious C String Manipulation Program!\n");
    char str[50];
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Your input: %s\n", str);

    int length = strlen(str);
    printf("Length of the input string is %d\n", length);

    int vowels = 0, consonants = 0, digits = 0, spaces = 0, symbols = 0;

    for(int i=0; i<length; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vowels++;

        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            consonants++;

        else if(str[i] >= '0' && str[i] <= '9')
            digits++;

        else if(str[i] == ' ')
            spaces++;

        else
            symbols++;
    }

    printf("Number of Vowels: %d\n", vowels);
    printf("Number of Consonants: %d\n", consonants);
    printf("Number of Digits: %d\n", digits);
    printf("Number of Spaces: %d\n", spaces);
    printf("Number of Symbols: %d\n", symbols);

    char reversed_str[length];
    int j = 0;

    for(int i=length-1; i>=0; i--){
        reversed_str[j] = str[i];
        j++;
    }

    reversed_str[j] = '\0';

    printf("Reversed String: %s\n", reversed_str);

    char first_half[length/2], second_half[length/2];
    j = 0;

    for(int i=0; i<length/2; i++){
        first_half[j] = str[i];
        j++;
    }
    first_half[j] = '\0';

    j = 0;
    for(int i=length/2; i<length; i++){
        second_half[j] = str[i];
        j++;
    }
    second_half[j] = '\0';

    printf("First Half of the String: %s\n", first_half);
    printf("Second Half of the String: %s\n", second_half);

    char new_string[length];
    j = 0;

    for(int i=0; i<length; i++){
        if(str[i] == ' ')
            new_string[j] = '-';
        else
            new_string[j] = str[i];
        j++;
    }

    new_string[j] = '\0';

    printf("New Modified String: %s\n", new_string);

    return 0;
}