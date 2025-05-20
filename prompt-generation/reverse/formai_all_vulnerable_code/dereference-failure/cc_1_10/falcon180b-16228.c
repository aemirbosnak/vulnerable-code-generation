//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define WATERMARK_LENGTH 10

typedef struct {
    char* text;
    int length;
} Text;

typedef struct {
    char* watermark;
    int length;
} Watermark;

Text* createText(char* str) {
    int len = strlen(str);
    Text* text = malloc(sizeof(Text));
    text->text = malloc(sizeof(char) * (len + 1));
    strcpy(text->text, str);
    text->length = len;
    return text;
}

Watermark* createWatermark(char* str) {
    int len = strlen(str);
    Watermark* watermark = malloc(sizeof(Watermark));
    watermark->watermark = malloc(sizeof(char) * (len + 1));
    strcpy(watermark->watermark, str);
    watermark->length = len;
    return watermark;
}

int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char* addWatermark(Text* text, Watermark* watermark) {
    int watermark_index = getRandom(0, text->length - WATERMARK_LENGTH);
    char* new_text = malloc(sizeof(char) * (text->length + WATERMARK_LENGTH));
    strncpy(new_text, text->text, watermark_index);
    strcat(new_text, watermark->watermark);
    strcat(new_text, text->text + watermark_index);
    free(text->text);
    text->text = new_text;
    text->length += WATERMARK_LENGTH;
    return new_text;
}

int main() {
    srand(time(NULL));
    Text* text = createText("Hello, world!");
    Watermark* watermark = createWatermark("My watermark");
    char* watermarked_text = addWatermark(text, watermark);
    printf("%s\n", watermarked_text);
    free(text->text);
    free(watermark->watermark);
    free(text);
    free(watermark);
    return 0;
}