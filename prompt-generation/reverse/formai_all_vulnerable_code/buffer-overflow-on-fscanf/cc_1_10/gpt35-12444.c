//FormAI DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/* Constants */
#define IMAGE_SIZE 1000
#define DATA_SIZE 200
#define BITS_PER_BYTE 8
#define THREADS_NUM 4

/* Global variables */
int image[IMAGE_SIZE][IMAGE_SIZE];  // Image matrix
char data[DATA_SIZE];               // Message to be hidden
unsigned int data_size;             // Size of the message in bytes
unsigned int data_bits;             // Size of the message in bits
unsigned int current_bit;           // Current bit being processed

// Mutex
pthread_mutex_t mutex;

// Function to convert an integer to a binary string
void decimal_to_binary(int decimal, char *binary) {
    int i, j;
    for (i = 7; i >= 0; i--) {
        j = decimal >> i;
        if (j & 1) {
            binary[7-i] = '1';
        } else {
            binary[7-i] = '0';
        }
    }
}

// Function to convert a binary string to an integer
int binary_to_decimal(char *binary) {
    int decimal = 0, base = 1, i;
    for (i = 7; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to hide a bit in a pixel of the image
void hide_bit(int i, int j) {
    char binary[8];
    decimal_to_binary(image[i][j], binary);
    binary[7] = (data[current_bit / BITS_PER_BYTE] >> (BITS_PER_BYTE - 1 - current_bit % BITS_PER_BYTE) & 1) + '0';
    current_bit++;
    image[i][j] = binary_to_decimal(binary);
}

// Thread function to hide bits in a section of the image
void *thread_function(void *arg) {
    int id = *(int *)arg;
    int i, j;
    while (current_bit < data_bits) {
        // Lock mutex
        pthread_mutex_lock(&mutex);

        // Hide bits in the section
        for (i = id * IMAGE_SIZE / THREADS_NUM; i < (id + 1) * IMAGE_SIZE / THREADS_NUM; i++) {
            for (j = 0; j < IMAGE_SIZE; j++) {
                if (current_bit < data_bits) {
                    hide_bit(i, j);
                } else {
                    break;
                }
            }
        }

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

// Function to read the image from file
void read_image() {
    int i, j, pixel;
    FILE *fp = fopen("image.txt", "r");
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            fscanf(fp, "%d", &pixel);
            image[i][j] = pixel;
        }
    }
    fclose(fp);
}

// Function to write the image to file
void write_image() {
    int i, j;
    FILE *fp = fopen("steg_image.txt", "w");
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function to read the message to be hidden from file
void read_data() {
    FILE *fp = fopen("data.txt", "r");
    fgets(data, DATA_SIZE, fp);
    fclose(fp);
    data_size = strlen(data) - 1;
    data_bits = data_size * BITS_PER_BYTE;
    current_bit = 0;
}

int main() {
    pthread_t threads[THREADS_NUM];
    int thread_ids[THREADS_NUM];
    int i;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Read the image and message to be hidden
    read_image();
    read_data();

    // Create and run threads
    for (i = 0; i < THREADS_NUM; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write the stegotext to file
    write_image();

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}