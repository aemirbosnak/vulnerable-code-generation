//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random integer between min and max
int random_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random character from a given character set
char random_char(char* char_set, int set_len)
{
    return char_set[random_int(0, set_len - 1)];
}

// Function to generate a secure password
char* generate_password(int length, int num_count, int sym_count)
{
    // Declare character sets
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_-+={}[]\\|;:'\",.<>/?";
    
    // Calculate number of letters based on password length, number count and symbol count
    int letter_count = length - num_count - sym_count;
    
    // Initialize password array
    char* password = (char*)malloc((length + 1) * sizeof(char));
    password[length] = '\0';
    
    // Generate letters
    for(int i = 0; i < letter_count; i++)
    {
        if(i % 2 == 0)
        {
            password[i] = random_char(lower, 26);
        }
        else
        {
            password[i] = random_char(upper, 26);
        }
    }
    
    // Generate numbers
    for(int i = letter_count; i < length - sym_count; i++)
    {
        password[i] = random_char(numbers, 10);
    }
    
    // Generate symbols
    for(int i = length - sym_count; i < length; i++)
    {
        password[i] = random_char(symbols, 30);
    }
    
    // Shuffle password
    for(int i = 0; i < length; i++)
    {
        int j = random_int(i, length - 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    return password;
}

int main()
{
    srand(time(NULL));
    int length, num_count, sym_count;
    
    printf("Enter password length (min 8): ");
    scanf("%d", &length);
    while(length < 8)
    {
        printf("Password length should be at least 8. Try again: ");
        scanf("%d", &length);
    }
    
    printf("Enter number count: ");
    scanf("%d", &num_count);
    
    printf("Enter symbol count: ");
    scanf("%d", &sym_count);
    
    char* password = generate_password(length, num_count, sym_count);
    printf("Generated password: %s", password);
    free(password);
    
    return 0;
}