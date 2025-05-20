//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include<stdio.h>
#include<string.h>

int main()
{
    char name[50];
    char temp[50];
    char message[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is: %s\n", name);
    int len = strlen(name);
    for(int i=0; i<len; i++){
        temp[i] = name[i];
    }
    printf("Your name backwards is: ");
    for(int i=len-1; i>=0; i--){
        printf("%c", name[i]);
    }
    printf("\n");
    printf("Your name in uppercase is: ");
    for(int i=0; i<len; i++){
        printf("%c", toupper(name[i]));
    }
    printf("\n");
    printf("Your name in lowercase is: ");
    for(int i=0; i<len; i++){
        printf("%c", tolower(name[i]));
    }
    printf("\n");
    printf("Your name with first letter capitalized is: ");
    temp[0] = toupper(temp[0]);
    for(int i=0; i<len; i++){
        printf("%c", temp[i]);
    }
    printf("\n");
    printf("Enter your message: ");
    scanf("%s", message);
    printf("Your message is: %s\n", message);
    int msglen = strlen(message);
    int matches = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<msglen; j++){
            if(name[i] == message[j]){
                matches++;
            }
        }
    }
    printf("Your name matches %d characters in your message.\n", matches);
    return 0;
}