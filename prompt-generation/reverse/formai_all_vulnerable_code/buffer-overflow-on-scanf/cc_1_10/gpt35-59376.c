//FormAI DATASET v1.0 Category: modern Encryption ; Style: recursive
#include<stdio.h> 
#include<string.h> 

unsigned char encrypt(unsigned char *str, int index, int key)
{
    //base case
    if(index == strlen(str))
        return str[index];
    
    //recursive case
    else
        return (str[index] ^ key) + encrypt(str, index + 1, key);
}

unsigned char decrypt(unsigned char *str, int index, int key)
{
    //base case
    if(index == strlen(str))
        return str[index];
    
    //recursive case
    else
        return (str[index] - key) ^ decrypt(str, index + 1, key);
}


int main()
{
    unsigned char message[100], encrypted_message[100], decrypted_message[100];
    int key;
    printf("Enter message to be encrypted: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%d", &key);
    
    //encrypt the message
    for(int i=0; i<strlen(message); i++)
        encrypted_message[i] = encrypt(message, i, key);
    encrypted_message[strlen(message)] = '\0';
    
    //decrypt the message
    for(int i=0; i<strlen(encrypted_message); i++)
        decrypted_message[i] = decrypt(encrypted_message, i, key);
    decrypted_message[strlen(encrypted_message)] = '\0';
    
    //print the results
    printf("\nOriginal message: %s\n", message);
    printf("\nEncrypted message: %s\n", encrypted_message);
    printf("\nDecrypted message: %s\n", decrypted_message);
    
    return 0;
}