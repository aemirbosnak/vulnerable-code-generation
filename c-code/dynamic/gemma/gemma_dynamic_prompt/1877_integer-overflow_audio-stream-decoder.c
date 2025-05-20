#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int buffer[10] = { 0 };
    int data = 0;
    int i = 0;

    // Loop to receive data
    while (1)
    {
        // Read data from stream
        scanf("%d", &data);

        // Check if data is valid
        if (data < 0 || data > 255)
        {
            break;
        }

        // Overflow the buffer
        buffer[i] = data + 1000000;
        i++;

        // If the buffer is full, process it
        if (i == 10)
        {
            // Decode the data
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", buffer[j]);
            }

            printf("\n");

            i = 0;
        }
    }

    return 0;
}
