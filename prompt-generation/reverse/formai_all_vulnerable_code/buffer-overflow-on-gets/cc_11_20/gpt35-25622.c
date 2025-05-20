//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    printf("Enter a string: ");
    gets(input_string);

    int length_of_string = strlen(input_string);
    int word_count = 1;

    for(int i=0; i<length_of_string; i++) {
        if(input_string[i]==' ' && input_string[i+1]!=' ') {
            word_count++;
        }
    }

    printf("\nThe length of the string is %d.\n", length_of_string);
    printf("\nThe number of words in the string is %d.\n", word_count);

    for(int i=0; i<length_of_string; i++) {
        if(input_string[i]>='a' && input_string[i]<='z') {
            input_string[i] -= 32;
        }
    }

    printf("\nThe string in uppercase is: ");
    puts(input_string);

    char reversed_string[100];
    int j=0;

    for(int i=length_of_string-1; i>=0; i--) {
        reversed_string[j] = input_string[i];
        j++;
    }

    reversed_string[j] = '\0';

    printf("\nThe reversed string is: %s\n", reversed_string);

    char substring[20];
    int substring_index = 0;

    for(int i=0; i<length_of_string; i++) {
        if(input_string[i]=='a' && input_string[i+1]=='b') {
            for(int j=i; j<i+10; j++) {
                substring[substring_index] = input_string[j];
                substring_index++;
            }
            substring[substring_index] = '\0';
            break;
        }
    }

    if(strlen(substring)>0) {
        printf("\nThe substring containing 'ab' is: %s\n", substring);
    } else {
        printf("\nThe string does not contain 'ab'\n");
    }

    return 0;
}