//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    uint8_t data[1024];
    uint32_t checksum;
} buffer_t;

void calculate_checksum(buffer_t* buffer) {
    uint32_t temp_sum = 0;
    for (int i = 0; i < 1024; i++) {
        temp_sum += buffer->data[i];
    }
    buffer->checksum = temp_sum;
}

void print_buffer(buffer_t* buffer) {
    printf("Buffer contents:\n");
    for (int i = 0; i < 1024; i++) {
        printf("%02x ", buffer->data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\nChecksum: 0x%08x\n", buffer->checksum);
}

int main() {
    buffer_t my_buffer;
    char input_string[256];

    printf("Enter data to be stored in the buffer (max 255 characters):\n");
    scanf("%s", input_string);

    int string_length = strlen(input_string);

    if (string_length > 255) {
        printf("Error: String length exceeds buffer size.\n");
        return 1;
    }

    memcpy(my_buffer.data, input_string, string_length);

    calculate_checksum(&my_buffer);

    print_buffer(&my_buffer);

    return 0;
}