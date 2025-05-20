//FormAI DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

int main()
{
    char secret_message[] = "AOSMOL CVMWZOBS GSVIV ZWB ZIV GZPV DZH SVMHS ZMW DRGS GSV JFVHG GL DSZG SVZW ZHH ZPV SVOKZ GH GNV, ZOZMW HZKGRLM GSV HZU XZHGOV!";

    printf("Before decryption: %s\n", secret_message);

    // Decrypting the message using the Caesar Cipher method
    int key = 18;
    int shift = 26 - key;

    for(int i=0; i<strlen(secret_message); i++)
    {
        char c = secret_message[i];

        if(c >= 'A' && c <= 'Z')
        {
            c = (c + shift - 65) % 26 + 65;
        }

        secret_message[i] = c;
    }

    printf("After decryption: %s\n", secret_message);

    // Reversing the message
    for(int i=0, j=strlen(secret_message)-1; i<j; i++, j--)
    {
        char temp = secret_message[i];
        secret_message[i] = secret_message[j];
        secret_message[j] = temp;
    }

    printf("Reversed message: %s\n", secret_message);

    // Extracting the secret word
    int startIndex = 9;
    int endIndex = 16;

    char secret_word[8];
    int index = 0;

    for(int i=startIndex; i<endIndex+1; i++)
    {
        secret_word[index] = secret_message[i];
        index++;
    }

    secret_word[index] = '\0';

    printf("The secret word is: %s\n", secret_word);

    return 0;
}