//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSG_LEN 256

//Function to generate a watermark based on the input data and secret key
void generate_watermark(unsigned char *input_data, unsigned char *secret_key, unsigned char *watermark)
{
    int i, j;

    //XOR the input data and secret key to generate the watermark
    for(i=0, j=0; i<strlen(input_data) && j<strlen(secret_key); i++, j++)
    {
        watermark[i] = input_data[i] ^ secret_key[j];
    }

    //Pad the watermark with zeroes to make it the same length as the input data
    while(i < strlen(input_data))
    {
        watermark[i] = '0';
        i++;
    }

    watermark[i] = '\0';
}

//Function to insert the watermark into the input data
void insert_watermark(unsigned char *input_data, unsigned char *watermark)
{
    int i, j;

    //Insert the watermark at the start of the input data
    for(i=0, j=0; i<strlen(watermark) && j<strlen(input_data); i++, j++)
    {
        input_data[j] = watermark[i];
    }
}

//Function to check if the watermark is present in the received data
int check_watermark(unsigned char *received_data, unsigned char *secret_key)
{
    int i, j;
    unsigned char watermark[MAX_MSG_LEN];

    //Generate the watermark based on the received data and secret key
    generate_watermark(received_data, secret_key, watermark);

    //Check if the generated watermark is present in the received data
    for(i=0, j=0; i<strlen(received_data) && j<strlen(watermark); i++, j++)
    {
        if(received_data[i] != watermark[j])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    unsigned char input_data[MAX_MSG_LEN], secret_key[MAX_MSG_LEN], watermark[MAX_MSG_LEN], received_data[MAX_MSG_LEN];
    int choice, check;

    do
    {
        printf("\n1. Generate Watermark\n2. Insert Watermark\n3. Check Watermark\n4. Exit\nEnter choice(1-4): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter input data: ");
                scanf("%s", input_data);
                printf("Enter secret key: ");
                scanf("%s", secret_key);

                generate_watermark(input_data, secret_key, watermark);
                printf("Generated Watermark: %s\n", watermark);
                break;

            case 2:
                printf("\nEnter input data: ");
                scanf("%s", input_data);

                if(strlen(input_data) < MAX_MSG_LEN/2)
                {
                    printf("Enter watermark: ");
                    scanf("%s", watermark);

                    insert_watermark(input_data, watermark);
                    printf("Watermark inserted.\nModified input data: %s\n", input_data);
                }
                else
                {
                    printf("Input data too large. Maximum allowed size is %d bytes.\n", MAX_MSG_LEN/2);
                }
                break;

            case 3:
                printf("\nEnter received data: ");
                scanf("%s", received_data);
                printf("Enter secret key: ");
                scanf("%s", secret_key);

                check = check_watermark(received_data, secret_key);

                if(check)
                {
                    printf("Watermark present.\n");
                }
                else
                {
                    printf("Watermark not present.\n");
                }
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(1);

    return 0;
}