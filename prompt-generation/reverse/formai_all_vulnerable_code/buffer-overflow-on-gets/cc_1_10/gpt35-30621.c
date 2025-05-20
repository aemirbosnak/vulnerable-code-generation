//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
/* 
    Romeo and Juliet - A Spam Detection System
    
    In fair Verona, where we set our scene, 
    a program designed to catch spam obscene.
    With C code sharp as any rapier keen,
    this Spam Detection System will reign supreme.
    
    The user inputs a message with care,
    and in an array each word will be fair.
    Each word will be checked with utmost care,
    to see if it's spam, with code beyond compare.
    
    To detect the spam, we will have a list,
    of words considered spam, a blacklist if you insist.
    Words like "buy", "discount" and "lottery" exist,
    and if found in a message, they shall be dismissed.
    
    The program will compare each word in a loop,
    with the words in the blacklist, a check quite astute.
    If a word is spam, a flag shall salute,
    and the message will be marked as spam too, it's absolute!
    
    Thus, the message will be either allowed or blocked,
    with the decision made by our Spam Detection System, unlocked.
    No more worry about spam, your Inbox is secured, locked,
    by this C code, born anew, with elegance and logic, stocked.
*/

#include <stdio.h>
#include <string.h>

// A function to check if the word is spam or not
int is_spam(char word[]){
    // A list of spam words
    char blacklist[][20] = {"buy", "discount", "lottery", "prize", "cash", "offer", "bonus", "win", "free", "save"};

    int i, size = sizeof(blacklist) / sizeof(blacklist[0]);
    for(i=0; i<size; i++){
        if(strcmp(word, blacklist[i]) == 0)
            return 1; // The word is spam
    }
    return 0; // The word is not spam
}

int main(){
    printf("Welcome to Romeo and Juliet Spam Detection System!\n\n");

    char message[500], word[20], output[500] = "";
    printf("Please enter your message: ");
    gets(message); // Gets the message from the user

    int i, j, flag;
    for(i=0; message[i]!='\0'; i++){
        // Extracting each word from the message
        for(j=0; message[i]!=' ' && message[i]!='\0'; j++, i++){
            word[j] = message[i];
        }
        word[j] = '\0';

        // Checking if the word is spam or not
        flag = is_spam(word);

        // If the word is spam, mark the message as spam
        if(flag){
            strcat(output, "***SPAM*** ");
            strcat(output, word);
            strcat(output, " ");
        }

        // If the word is not spam, append it to the message
        else{
            strcat(output, word);
            strcat(output, " ");
        }
    }
    
    // Printing the final message
    printf("\nYour modified message is:\n");
    puts(output);

    return 0;
}