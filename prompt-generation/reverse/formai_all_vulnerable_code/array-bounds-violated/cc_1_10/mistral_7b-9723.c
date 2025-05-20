//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    int length;
    char data[MAX];
} String;

void printString(String str){
    if(str.length > 0)
        printf("%c", str.data[str.length - 1]);
    printString((String){str.length - 1, str.data});
}

void printReverseString(String str){
    if(str.length > 0){
        printReverseString((String){str.length - 1, str.data});
        printf("%c", str.data[str.length - 1]);
    }
}

String concatenateStrings(String str1, String str2){
    String result;
    result.length = str1.length + str2.length + 1;
    strcpy(result.data, str1.data);
    strcat(result.data, str2.data);
    return result;
}

String shiftLeft(String str, int count){
    String result;
    if(str.length >= count)
        result = (String){str.length - count, str.data + count};
    else{
        result.length = 0;
        return result;
    }
    strncpy(result.data, str.data, str.length);
    return result;
}

String shiftRight(String str, int count){
    String result;
    if(str.length >= count){
        result.length = str.length - count;
        strncpy(result.data, str.data + count, result.length + 1);
        result.data[result.length] = '\0';
    }
    else{
        result.length = 0;
        return result;
    }
    return result;
}

int main(int argc, char *argv[])
{
    String str1 = {"Hello", 5};
    String str2 = {"World", 5};

    printf("Original strings:\n");
    printString(str1);
    printf(" ");
    printString(str2);
    printf("\n");

    printf("Concatenated strings:\n");
    printString(concatenateStrings(str1, str2));
    printf("\n");

    printf("Shift left by 2:\n");
    printString(shiftLeft(str1, 2));
    printf("\n");

    printf("Shift right by 2:\n");
    printString(shiftRight(str2, 2));
    printf("\n");

    printf("Reverse of string str1:\n");
    printReverseString(str1);
    printf("\n");

    String str3 = shiftLeft(str1, 2);
    String str4 = shiftRight(str2, 2);
    String str5 = concatenateStrings(str3, str4);

    printf("Shifted, concatenated and reversed string:\n");
    printReverseString(str5);
    printf("\n");

    return 0;
}