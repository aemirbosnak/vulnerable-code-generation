//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main(){

    char message[] = "Why don't scientists trust atoms? Because they make up everything...";
    char secret_message[strlen(message)];
    int i, j=0;
    printf("Original message: \"%s\"\n", message);

    // Reverse the message
    printf("Reversed message: \"");
    for(i=strlen(message)-1;i>=0;i--){
        printf("%c", message[i]);
    }
    printf("\"\n");

    // Remove spaces from the message
    printf("Message without spaces: \"");
    for(i=0;i<strlen(message);i++){
        if (message[i] != ' '){
            printf("%c", message[i]);
        }
    }
    printf("\"\n");

    // Encrypt the message with Caesar cipher!
    printf("Encrypted message: \"");
    for(i=0;i<strlen(message);i++){
        if (message[i] >= 'a' && message[i] <= 'z'){
            secret_message[j] = (message[i] - 'a' + 3) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z'){
            secret_message[j] = (message[i] - 'A' + 3) % 26 + 'A';
        }
        else{
            secret_message[j] = message[i];
        }
        j++;
    }
    secret_message[j] = '\0';
    printf("%s\"\n", secret_message);

    // Now let's decrypt the message
    printf("Decrypted message: \"");
    j=0;
    for(i=0;i<strlen(secret_message);i++){
        if (secret_message[i] >= 'a' && secret_message[i] <= 'z'){
            message[j] = (secret_message[i] - 'a' + 23) % 26 + 'a';
        }
        else if (secret_message[i] >= 'A' && secret_message[i] <= 'Z'){
            message[j] = (secret_message[i] - 'A' + 23) % 26 + 'A';
        }
        else{
            message[j] = secret_message[i];
        }
        j++;
    }
    message[j] = '\0';
    printf("%s\"\n", message);

    return 0;
}