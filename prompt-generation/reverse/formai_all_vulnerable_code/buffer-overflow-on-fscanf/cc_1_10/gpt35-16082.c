//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILENAME_LEN 256
#define MAX_MSG_LEN 256
#define MAX_BINARY_LEN 8
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

void read_image(char *filename, Image *img)
{
    FILE *fp;
    char buffer[MAX_FILENAME_LEN];
    
    sprintf(buffer, "images/%s", filename);
    fp = fopen(buffer, "r");
    
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }
    
    fscanf(fp, "%d %d", &img->width, &img->height);
    
    img->pixels = (int **) malloc(img->height * sizeof(int *));
    
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = (int *) malloc(img->width * sizeof(int));
    }
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(fp, "%d", &img->pixels[i][j]);
        }
    }
    
    fclose(fp);
}

void save_image(char *filename, Image *img)
{
    FILE *fp;
    char buffer[MAX_FILENAME_LEN];
    
    sprintf(buffer, "images/%s", filename);
    fp = fopen(buffer, "w");
    
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }
    
    fprintf(fp, "%d %d\n", img->width, img->height);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d ", img->pixels[i][j]);
        }
        
        fprintf(fp, "\n");
    }
    
    fclose(fp);
}

int *int_to_bin(int num)
{
    static int bin[MAX_BINARY_LEN];
    
    for (int i = 0; i < MAX_BINARY_LEN; i++) {
        bin[i] = num % 2;
        num = num / 2;
    }
    
    return bin;
}

int bin_to_int(int *bin)
{
    int num = 0;
    
    for (int i = 0; i < MAX_BINARY_LEN; i++) {
        num += bin[i] * pow(2, i);
    }
    
    return num;
}

void apply_watermark(Image *img, char *msg)
{
    int msg_len = strlen(msg);
    int key[msg_len][MAX_BINARY_LEN];
    
    for (int i = 0; i < msg_len; i++) {
        int *bin = int_to_bin(msg[i]);
        
        for (int j = 0; j < MAX_BINARY_LEN; j++) {
            key[i][j] = bin[j];
        }
    }
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int pixel = img->pixels[i][j];
            
            if (pixel > 0) {
                int x = i % msg_len;
                int *bin = int_to_bin(pixel);
                
                for (int k = 0; k < MAX_BINARY_LEN; k++) {
                    if (key[x][k] == 1) {
                        bin[k] = (bin[k] == 0) ? 1 : 0;
                    }
                }
                
                img->pixels[i][j] = bin_to_int(bin);
            }
        }
    }
}

char *extract_watermark(Image *img, int msg_len)
{
    char *msg = (char *) malloc(msg_len * sizeof(char));
    int key[msg_len][MAX_BINARY_LEN];
    
    for (int i = 0; i < msg_len; i++) {
        int *bin = int_to_bin(msg[i]);
        
        for (int j = 0; j < MAX_BINARY_LEN; j++) {
            key[i][j] = (rand() % 2 == 1) ? 1 : 0;
        }
    }
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int pixel = img->pixels[i][j];
            
            if (pixel > 0) {
                int x = i % msg_len;
                int *bin = int_to_bin(pixel);
                
                for (int k = 0; k < MAX_BINARY_LEN; k++) {
                    if (key[x][k] == 1) {
                        bin[k] = (bin[k] == 0) ? 1 : 0;
                    }
                }
                
                img->pixels[i][j] = bin_to_int(bin);
            }
        }
    }
    
    return msg;
}

int main()
{
    char filename[MAX_FILENAME_LEN];
    char msg[MAX_MSG_LEN];
    Image img;
    
    printf("Enter the image filename: ");
    scanf("%s", filename);
    
    printf("Enter the message to watermark: ");
    scanf("%s", msg);
    
    read_image(filename, &img);
    apply_watermark(&img, msg);
    sprintf(filename, "watermarked-%s", filename);
    save_image(filename, &img);
    
    printf("Watermark applied successfully!\n");
    
    printf("Extracting watermark...\n");
    
    read_image(filename, &img);
    char *watermark = extract_watermark(&img, strlen(msg));
    
    printf("Watermark extracted successfully: %s\n", watermark);
    
    return 0;
}