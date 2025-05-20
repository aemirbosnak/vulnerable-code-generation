//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random string of length n
char* rand_str(int n) {
    char* str = (char*) malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to embed a watermark into an image
void embed_watermark(int* img, int w, int h, char* watermark) {
    int n = strlen(watermark);
    int x = rand_num(0, w - n);
    int y = rand_num(0, h - n);
    for (int i = 0; i < n; i++) {
        img[y * w + x + i] += rand_num(1, 5);
    }
}

// Function to extract a watermark from an image
char* extract_watermark(int* img, int w, int h) {
    int n = w * h;
    int* freq = (int*) malloc(26 * sizeof(int));
    memset(freq, 0, 26 * sizeof(int));
    char* str = (char*) malloc(n + 1);
    for (int i = 0; i < n; i++) {
        int c = img[i] % 26 + 'a';
        freq[c - 'a']++;
        str[i] = c;
    }
    str[n] = '\0';
    char* res = NULL;
    int max_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            res = (char*) malloc(n + 1);
            memcpy(res, str, n);
            res[n] = '\0';
        }
    }
    free(freq);
    return res;
}

int main() {
    int w = 512, h = 512;
    int* img = (int*) malloc(w * h * sizeof(int));
    memset(img, 0, w * h * sizeof(int));
    char* watermark = rand_str(10);
    embed_watermark(img, w, h, watermark);
    FILE* fp = fopen("image.bmp", "wb");
    fwrite(img, sizeof(int), w * h, fp);
    fclose(fp);
    char* res = extract_watermark(img, w, h);
    if (res!= NULL) {
        printf("Extracted watermark: %s\n", res);
    } else {
        printf("Watermark not found.\n");
    }
    free(img);
    free(res);
    return 0;
}