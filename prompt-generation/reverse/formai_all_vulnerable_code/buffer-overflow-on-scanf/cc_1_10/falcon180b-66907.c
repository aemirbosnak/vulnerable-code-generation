//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_DATA_LENGTH 1000

int main()
{
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
    
    printf("Enter the key: ");
    scanf("%s", key);
    
    printf("Enter the data to be encrypted: ");
    scanf("%s", data);
    
    int key_length = strlen(key);
    int data_length = strlen(data);
    
    if (key_length > MAX_KEY_LENGTH || data_length > MAX_DATA_LENGTH)
    {
        printf("Error: Key or data length exceeds maximum limit.\n");
        exit(1);
    }
    
    char encrypted_data[MAX_DATA_LENGTH];
    int encrypted_data_length = 0;
    
    for (int i = 0; i < data_length; i++)
    {
        if (isalpha(data[i]))
        {
            int key_index = toupper(key[i % key_length]) - 65;
            int data_index = toupper(data[i]) - 65;
            
            if (key_index >= 0 && key_index <= 25)
            {
                encrypted_data[encrypted_data_length++] = 'A' + ((data_index - key_index + 26) % 26);
            }
            else
            {
                encrypted_data[encrypted_data_length++] = data[i];
            }
        }
        else
        {
            encrypted_data[encrypted_data_length++] = data[i];
        }
    }
    
    printf("Encrypted data: %s\n", encrypted_data);
    
    return 0;
}