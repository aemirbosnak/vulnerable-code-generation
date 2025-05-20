//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STEGS 100

struct steg_img {
    int width;
    int height;
    char *data;
};

struct steg_msg {
    char *message;
    int length;
};

void hide_msg(struct steg_img *img, struct steg_msg *msg) {
    int i, j;
    char c;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            c = img->data[i * img->width + j];
            if (isalpha(c)) {
                c = (c - 'a' + msg->message[i * img->width + j] - 'a') % 26 + 'a';
            }
            img->data[i * img->width + j] = c;
        }
    }
}

void reveal_msg(struct steg_img *img, struct steg_msg *msg) {
    int i, j;
    char c;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            c = img->data[i * img->width + j];
            if (isalpha(c)) {
                c = (c - 'a' + 'a') % 26 + 'a';
            }
            msg->message[i * img->width + j] = c;
        }
    }
}

int main() {
    struct steg_img img;
    struct steg_msg msg;
    char *image_path, *message_path;
    FILE *image_file, *message_file;
    int i, j;
    char c;

    image_path = "image.jpg";
    message_path = "message.txt";

    image_file = fopen(image_path, "r");
    message_file = fopen(message_path, "r");

    img.width = 100;
    img.height = 100;
    img.data = (char *)malloc(img.width * img.height * sizeof(char));

    msg.message = (char *)malloc(img.width * img.height * sizeof(char));
    msg.length = 100;

    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            c = fgetc(image_file);
            img.data[i * img.width + j] = c;
        }
    }

    for (i = 0; i < msg.length; i++) {
        c = fgetc(message_file);
        msg.message[i] = c;
    }

    hide_msg(&img, &msg);

    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            c = img.data[i * img.width + j];
            printf("%c", c);
        }
        printf("\n");
    }

    reveal_msg(&img, &msg);

    for (i = 0; i < msg.length; i++) {
        printf("%c", msg.message[i]);
    }

    return 0;
}