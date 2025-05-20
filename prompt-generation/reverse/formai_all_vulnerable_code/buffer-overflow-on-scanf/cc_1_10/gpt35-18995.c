//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str, int len) {
    int i;
    char temp;
    for(i=0;i<len/2;i++) {
        temp = *(str+i);
        *(str+i) = *(str+len-i-1);
        *(str+len-i-1) = temp;
    }
}

// Function to convert string to uppercase
void uppercase(char *str) {
    int i;
    for(i=0;i<strlen(str);i++) {
        if(*(str+i) >= 'a' && *(str+i) <= 'z')
            *(str+i) = *(str+i) - 'a' + 'A';
    }
}

// Function to concatenate strings
void concatenate(char *dest, char *src) {
    strcat(dest, " ");
    strcat(dest, src);
}

int main() {
    char name[50], age_string[10], message[100] = "My love, ";
    int age;
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    sprintf(age_string, "%d", age);

    concatenate(message, name);
    concatenate(message, "!");
    concatenate(message, " I love you more than ");
    concatenate(message, age_string);
    concatenate(message, " sunsets on a summer day.");

    uppercase(name);
    reverse(name, strlen(name));
    concatenate(message, " Your name backwards is ");
    concatenate(message, name);
    concatenate(message, ", and it sounds just as sweet to me.");

    printf("%s", message);

    return 0;
}