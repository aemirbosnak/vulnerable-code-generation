//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    char password[length+1];
    printf("Enter the characters to include in the password: ");
    scanf(" %[^\n]", password);
    password[length] = '\0';

    for(int i=0; i<length; i++) {
        char ch = password[i];
        if(ch >= 'a' && ch <= 'z') {
            printf("Enter the number of lowercase letters to include: ");
            scanf("%d", &length);
            for(int j=0; j<length; j++) {
                password[i+j] = 'a' + rand()%26;
            }
            i += length-1;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            printf("Enter the number of uppercase letters to include: ");
            scanf("%d", &length);
            for(int j=0; j<length; j++) {
                password[i+j] = 'A' + rand()%26;
            }
            i += length-1;
        }
        else if(ch >= '0' && ch <= '9') {
            printf("Enter the number of digits to include: ");
            scanf("%d", &length);
            for(int j=0; j<length; j++) {
                password[i+j] = '0' + rand()%10;
            }
            i += length-1;
        }
        else if(ch == '!') {
            printf("Enter the number of special characters to include: ");
            scanf("%d", &length);
            for(int j=0; j<length; j++) {
                password[i+j] = '!' + rand()%26;
            }
            i += length-1;
        }
    }
    printf("Generated password: %s\n", password);
    return 0;
}