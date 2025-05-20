//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 1000
#define PRIME_NUMBER 37
#define BASE 26

// Function to check if a number is prime
int is_prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

// Function to convert decimal to base 26
char* dec_to_base26(int n)
{
    int i = 0;
    char* str = (char*)malloc(MAX_SIZE*sizeof(char));
    do
    {
        str[i] = 'A' + n%26;
        n /= 26;
        i++;
    } while(n > 0);
    str[i] = '\0';
    return str;
}

// Function to generate public and private keys
void generate_keys(int* public_key, int* private_key)
{
    int i;
    for(i=0;i<2;i++)
    {
        do
        {
            *public_key = rand()%MAX_SIZE;
        } while(!is_prime(*public_key));

        *private_key = rand()%MAX_SIZE;
        while(!is_prime(*private_key))
        {
            *private_key = rand()%MAX_SIZE;
        }
    }
}

// Function to encrypt message
char* encrypt(char* message, int public_key)
{
    int i,j;
    char* encrypted_message = (char*)malloc(strlen(message)*sizeof(char));
    for(i=0;i<strlen(message);i++)
    {
        encrypted_message[i] = 'A' + ((message[i] + public_key)%26);
    }
    return encrypted_message;
}

// Function to decrypt message
char* decrypt(char* message, int private_key)
{
    int i,j;
    char* decrypted_message = (char*)malloc(strlen(message)*sizeof(char));
    for(i=0;i<strlen(message);i++)
    {
        decrypted_message[i] = 'A' + ((message[i] - private_key + 26)%26);
    }
    return decrypted_message;
}

// Main function
int main()
{
    int public_key, private_key;
    char* message;
    char* encrypted_message;
    char* decrypted_message;

    generate_keys(&public_key, &private_key);

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypted_message = encrypt(message, public_key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, private_key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}