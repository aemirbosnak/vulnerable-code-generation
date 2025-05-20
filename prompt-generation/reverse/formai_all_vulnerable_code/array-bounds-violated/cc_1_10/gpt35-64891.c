//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LEN 1000
#define MAX_WATERMARK_LEN 50
#define MAX_IMG_SIZE 1000

typedef struct {
    int width;
    int height;
    int pixels[MAX_IMG_SIZE][MAX_IMG_SIZE];
} Image;

typedef struct {
    char message[MAX_MSG_LEN];
    char watermark[MAX_WATERMARK_LEN];
} Data;

void add_watermark(Image* img, char* watermark) {
    int watermark_len = strlen(watermark);
    int x = 0;
    int y = 0;
    int i;
    
    for (i = 0; i < watermark_len; i++) {
        img->pixels[x][y] += watermark[i];
        x += (y + 1) / img->height;
        y = (y + 1) % img->height;
    }
}

Data extract_watermark(Image* img, int watermark_len) {
    Data data;
    int x = 0;
    int y = 0;
    int i;
    
    for (i = 0; i < watermark_len; i++) {
        data.watermark[i] = img->pixels[x][y] % 256;
        x += (y + 1) / img->height;
        y = (y + 1) % img->height;
    }
    data.watermark[watermark_len] = '\0';
    
    return data;
}

void embed_data(char* message, char* watermark, Image* img) {
    int message_len = strlen(message);
    int watermark_len = strlen(watermark);
    int i;
    
    for (i = 0; i < message_len; i += watermark_len) {
        char sub_message[MAX_WATERMARK_LEN];
        strncpy(sub_message, message + i, watermark_len);
        sub_message[watermark_len] = '\0';
        add_watermark(img, watermark);
    }
}

Data extract_data(Image* img, int message_len, int watermark_len) {
    Data data;
    int x = 0;
    int y = 0;
    int i;
    
    for (i = 0; i < message_len; i += watermark_len) {
        Data sub_data = extract_watermark(img, watermark_len);
        strcat(data.message, sub_data.watermark);
    }
    data.message[message_len] = '\0';
    
    return data;
}

int main() {
    Image img;
    Data data;
    char message[MAX_MSG_LEN];
    char watermark[MAX_WATERMARK_LEN];
    int message_len;
    int watermark_len;
    
    srand(time(NULL)); // seeding random generator
    
    printf("Enter message to embed: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message_len = strlen(message) - 1;
    message[message_len] = '\0'; // get rid of newline character
    
    printf("Enter watermark to use: ");
    fgets(watermark, MAX_WATERMARK_LEN, stdin);
    watermark_len = strlen(watermark) - 1;
    watermark[watermark_len] = '\0'; // get rid of newline character
    
    // initialize image with random pixels
    img.width = rand() % MAX_IMG_SIZE + 1;
    img.height = rand() % MAX_IMG_SIZE + 1;
    int i, j;
    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            img.pixels[i][j] = rand() % 256;
        }
    }
    
    embed_data(message, watermark, &img);
    
    printf("Message embedded successfully!\n");
    
    data = extract_data(&img, message_len, watermark_len);
    
    printf("Extracted message: %s\n", data.message);
    
    return 0;
}