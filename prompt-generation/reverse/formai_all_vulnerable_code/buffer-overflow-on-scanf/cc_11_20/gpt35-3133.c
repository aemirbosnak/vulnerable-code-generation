//FormAI DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {

    //Declare a string variable
    char str[100];

    //Prompt user to input string
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    //Print original string
    printf("\nOriginal String: %s\n", str);

    //Find length of string and print
    int len = strlen(str);
    printf("Length of String: %d\n", len);

    //Convert string to uppercase and print
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    printf("Uppercase String: %s\n", str);

    //Reverse the string and print
    char temp;
    int i, j;
    for(i = 0, j = len-1; i<j;  i++, j--){

        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

    }
    printf("Reversed String: %s\n", str);

    //Count vowels in the string and print
    int vowels = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
                vowels++;
        }
    }
    printf("Number of Vowels: %d\n", vowels);

    //Find the frequency of each character in the string and print
    int freq[256] = {0};
    for(int i = 0; str[i]; i++){
        freq[(int)str[i]]++;
    }
    for(int i = 0; i < 256; i++){
        if(freq[i]!=0){
            printf("Frequency of %c: %d\n", i, freq[i]);
        }
    }

    return 0;
}