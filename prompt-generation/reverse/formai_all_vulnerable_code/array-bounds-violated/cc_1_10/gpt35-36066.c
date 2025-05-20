//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_CHAR 100
#define MAX_LEN 20

char randChar() {
    int i, r;
    char c;
    for(i=0;i<10;i++) {
        r = rand() % (127 - 33) + 33;
    }
    c = r;
    return c;
}

int main() {
    int i, j, randNum;
    char password[MAX_LEN + 1];
    char symbols[] = "!@#$%^&*()_+-=";
    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    int length, num, sym, low, up;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Enter the number of numbers: ");
    scanf("%d", &num);
    printf("Enter the number of symbols: ");
    scanf("%d", &sym);
    printf("Enter the number of lowercase letters: ");
    scanf("%d", &low);
    printf("Enter the number of uppercase letters: ");
    scanf("%d", &up);
    
    if(length < (num + sym + low + up)) {
        printf("Error: Length is too small for provided number categories.\n");
        exit(1);
    }
    
    srand(time(NULL));
    
    for(i=0;i<num;i++) {
        randNum = rand() % 10; // Generate random number
        password[i] = numbers[randNum];
    }
    
    for(i=0;i<sym;i++) {
        randNum = rand() % strlen(symbols); // Generate random number
        password[i+num] = symbols[randNum];
    }
    
    for(i=0;i<low;i++) {
        randNum = rand() % strlen(lowercase); // Generate random number
        password[i+num+sym] = lowercase[randNum];
    }
    
    for(i=0;i<up;i++) {
        randNum = rand() % strlen(uppercase); // Generate random number
        password[i+num+sym+low] = uppercase[randNum];
    }
    
    for(i=num+sym+low+up;i<length;i++) {
        randNum = rand() % 4;
        if(randNum == 0) {
            password[i] = randChar();
        } else if(randNum == 1) {
            randNum = rand() % strlen(symbols);
            password[i] = symbols[randNum];
        } else if(randNum == 2) {
            randNum = rand() % strlen(lowercase);
            password[i] = lowercase[randNum];
        } else if(randNum == 3) {
            randNum = rand() % strlen(uppercase);
            password[i] = uppercase[randNum];
        } else {
            password[i] = ' ';
        }
    }
    
    password[length] = '\0';
    
    for(i=0;i<length;i++) {
        randNum = rand() % 2;
        if(randNum == 0) {
            printf("%c", password[i]);
        } else if(randNum == 1) {
            printf("%c", toupper(password[i]));
        }
    }
    
    printf("\n");
    
    return 0;
}