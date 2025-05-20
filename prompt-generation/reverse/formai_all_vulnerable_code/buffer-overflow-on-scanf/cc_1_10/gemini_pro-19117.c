//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define the maximum size of the input message
#define MAX_MESSAGE_SIZE 1024

// Define the size of the output hash
#define HASH_SIZE 32

// Create a function to hash a message using SHA-256
void hash_message(unsigned char *message, int message_size, unsigned char *hash)
{
    // Create a SHA-256 context
    SHA256_CTX context;
    SHA256_Init(&context);

    // Update the context with the message
    SHA256_Update(&context, message, message_size);

    // Finalize the context and get the hash
    SHA256_Final(hash, &context);
}

// Create a function to generate a random message
void generate_random_message(unsigned char *message, int message_size)
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random message
    for (int i = 0; i < message_size; i++)
    {
        message[i] = rand() % 256;
    }
}

// Create a function to print a hash
void print_hash(unsigned char *hash, int hash_size)
{
    // Print the hash in hexadecimal format
    for (int i = 0; i < hash_size; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Create a function to test the hash function
void test_hash_function()
{
    // Create a random message
    unsigned char message[MAX_MESSAGE_SIZE];
    generate_random_message(message, MAX_MESSAGE_SIZE);

    // Hash the message
    unsigned char hash[HASH_SIZE];
    hash_message(message, MAX_MESSAGE_SIZE, hash);

    // Print the message and the hash
    printf("Message: %s\n", message);
    printf("Hash: ");
    print_hash(hash, HASH_SIZE);
}

// Create a function to show the menu
void show_menu()
{
    printf("\n");
    printf("1. Hash a message\n");
    printf("2. Test the hash function\n");
    printf("3. Quit\n");
    printf("\n");
    printf("Enter your choice: ");
}

// Create a function to get the user's choice
int get_user_choice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Create the main function
int main()
{
    // Show the menu
    show_menu();

    // Get the user's choice
    int choice = get_user_choice();

    // Loop until the user quits
    while (choice != 3)
    {
        // Hash a message
        if (choice == 1)
        {
            // Get the message from the user
            unsigned char message[MAX_MESSAGE_SIZE];
            printf("Enter a message: ");
            scanf("%s", message);

            // Hash the message
            unsigned char hash[HASH_SIZE];
            hash_message(message, strlen(message), hash);

            // Print the message and the hash
            printf("Message: %s\n", message);
            printf("Hash: ");
            print_hash(hash, HASH_SIZE);
        }

        // Test the hash function
        else if (choice == 2)
        {
            test_hash_function();
        }

        // Show the menu
        show_menu();

        // Get the user's choice
        choice = get_user_choice();
    }

    return 0;
}