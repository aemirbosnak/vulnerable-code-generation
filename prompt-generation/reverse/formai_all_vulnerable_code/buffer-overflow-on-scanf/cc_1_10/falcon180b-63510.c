//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//function to calculate the hash of the email
unsigned int hash(char* str)
{
    unsigned int hash = 0;
    int i = 0;
    while(str[i])
    {
        hash += str[i];
        i++;
    }
    return hash % 100;
}

//function to check if the email is spam or not
bool is_spam(char* email, int* spam_count)
{
    FILE* fp = fopen("spam_words.txt", "r");
    char word[100];
    int count = 0;
    while(fscanf(fp, "%s", word)!= EOF)
    {
        if(strstr(email, word))
        {
            count++;
        }
    }
    fclose(fp);
    if(count >= 3)
    {
        (*spam_count)++;
        return true;
    }
    return false;
}

int main()
{
    char email[100];
    int spam_count = 0;
    while(true)
    {
        printf("Enter an email address: ");
        scanf("%s", email);
        if(is_spam(email, &spam_count))
        {
            printf("Spam detected in email: %s\n", email);
        }
        else
        {
            printf("No spam detected in email: %s\n", email);
        }
    }
    return 0;
}