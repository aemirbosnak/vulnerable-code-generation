//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 100

uint8_t calculate_checksum(uint8_t data[], int size);

int main()
{
    uint8_t data[MAX_SIZE];
    int size, i;

    printf("Enter size of data (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if(size > MAX_SIZE)
    {
        printf("Error: data size exceeds maximum allowed\n");
        return 1;
    }

    printf("Enter data (as integer values):\n");
    for(i = 0; i < size; i++)
    {
        printf("%d. ", i+1);
        scanf("%hhd", &data[i]);
    }

    uint8_t checksum = calculate_checksum(data, size);

    printf("Checksum: %d\n", checksum);

    printf("Enter received checksum: ");
    uint8_t received_checksum;
    scanf("%hhd", &received_checksum);

    if(received_checksum == checksum)
        printf("Checksums match. Data is valid.\n");
    else
        printf("Checksums do not match. Data may have been corrupted or tampered with.\n");

    return 0;
}

uint8_t calculate_checksum(uint8_t data[], int size)
{
    int i;
    uint16_t sum = 0;

    for(i = 0; i < size; i++)
        sum += data[i];

    uint8_t checksum = (uint8_t)(~sum); 
    return checksum;
}