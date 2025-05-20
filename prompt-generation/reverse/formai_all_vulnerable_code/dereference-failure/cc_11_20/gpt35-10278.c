//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define MAX_TXT 20000
#define MAX_LSB 16

#define CLEAR_LSB_1(x)   ((x) & ~0x1)
#define CLEAR_LSB_4(x)   ((x) & ~0xf)
#define CLEAR_LSB_8(x)   ((x) & ~0xff)
#define CLEAR_LSB_16(x)  ((x) & ~0xffff)

char *error_messages[] = {
        "Operation Successful",
        "No message file provided",
        "Unable to open message file",
        "Message file too large",
        "Unable to open input image file",
        "Unable to open output image file",
        "Unable to read input image file",
        "Unable to read message file",
        "Unable to write output image file",
        "Input image is not a bitmap file",
        "Input image is not in 24-bit color depth",
        "Input image is not large enough to accommodate the message",
        "Insufficient space to hide the message in the image",
};

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;

typedef struct bmp {
    byte magic[2];
    dword file_size;
    word reserved_word_1;
    word reserved_word_2;
    dword offset;
    dword header_size;
    dword image_width;
    dword image_height;
    word planes;
    word color_depth;
    dword compression_method;
    dword image_size;
    dword horizontal_bytes_per_pixel;
    dword vertical_bytes_per_pixel;
    dword palette_colors;
    dword important_colors;
} BMP;

int embed_text(const char *cover_image, const char *text_file, const char *output_image) {
    FILE *f_cover, *f_text, *f_output;
    BMP bmp;
    byte *bmp_data, *msg_data;
    dword i, j, img_sz, msg_sz;
    int bit_to_use, flag;
    char c;

    // open input image file
    f_cover = fopen(cover_image, "rb");
    if (!f_cover) {
        return ENOENT;
    }

    // read image header
    fread(bmp.magic, sizeof(char), 2, f_cover);
    fread(&bmp.file_size, sizeof(bmp.file_size), 1, f_cover);
    fread(&bmp.reserved_word_1, sizeof(bmp.reserved_word_1), 1, f_cover);
    fread(&bmp.reserved_word_2, sizeof(bmp.reserved_word_2), 1, f_cover);
    fread(&bmp.offset, sizeof(bmp.offset), 1, f_cover);
    fread(&bmp.header_size, sizeof(bmp.header_size), 1, f_cover);
    fread(&bmp.image_width, sizeof(bmp.image_width), 1, f_cover);
    fread(&bmp.image_height, sizeof(bmp.image_height), 1, f_cover);
    fread(&bmp.planes, sizeof(bmp.planes), 1, f_cover);
    fread(&bmp.color_depth, sizeof(bmp.color_depth), 1, f_cover);
    if (bmp.color_depth != 24) {
        fclose(f_cover);
        return ENODEV;
    }
    fread(&bmp.compression_method, sizeof(bmp.compression_method), 1, f_cover);
    fread(&bmp.image_size, sizeof(bmp.image_size), 1, f_cover);
    fread(&bmp.horizontal_bytes_per_pixel, sizeof(bmp.horizontal_bytes_per_pixel), 1, f_cover);
    fread(&bmp.vertical_bytes_per_pixel, sizeof(bmp.vertical_bytes_per_pixel), 1, f_cover);
    fread(&bmp.palette_colors, sizeof(bmp.palette_colors), 1, f_cover);
    fread(&bmp.important_colors, sizeof(bmp.important_colors), 1, f_cover);

    // calculate image size
    img_sz = bmp.image_width * bmp.image_height * 3;

    // allocate memory to store input data
    bmp_data = (byte *) malloc(img_sz);
    if (!bmp_data) {
        fclose(f_cover);
        return ENOMEM;
    }

    // read bmp data
    fread(bmp_data, sizeof(char), img_sz, f_cover);

    // open message file
    f_text = fopen(text_file, "rb");
    if (!f_text) {
        fclose(f_cover);
        free(bmp_data);
        return ENOENT;
    }

    // get message file size
    fseek(f_text, 0, SEEK_END);
    msg_sz = ftell(f_text);
    if (msg_sz > MAX_TXT) {
        fclose(f_cover);
        fclose(f_text);
        free(bmp_data);
        return EMSGSIZE;
    }

    // allocate memory to store message data
    msg_data = (byte *) malloc(msg_sz);
    if (!msg_data) {
        fclose(f_cover);
        fclose(f_text);
        free(bmp_data);
        return ENOMEM;
    }

    // read message data
    rewind(f_text);
    fread(msg_data, sizeof(char), msg_sz, f_text);

    // open output image file
    f_output = fopen(output_image, "wb");
    if (!f_output) {
        fclose(f_cover);
        fclose(f_text);
        free(bmp_data);
        free(msg_data);
        return EACCES;
    }

    // write header to output image
    fwrite(bmp.magic, sizeof(char), 2, f_output);
    fwrite(&bmp.file_size, sizeof(bmp.file_size), 1, f_output);
    fwrite(&bmp.reserved_word_1, sizeof(bmp.reserved_word_1), 1, f_output);
    fwrite(&bmp.reserved_word_2, sizeof(bmp.reserved_word_2), 1, f_output);
    fwrite(&bmp.offset, sizeof(bmp.offset), 1, f_output);
    fwrite(&bmp.header_size, sizeof(bmp.header_size), 1, f_output);
    fwrite(&bmp.image_width, sizeof(bmp.image_width), 1, f_output);
    fwrite(&bmp.image_height, sizeof(bmp.image_height), 1, f_output);
    fwrite(&bmp.planes, sizeof(bmp.planes), 1, f_output);
    fwrite(&bmp.color_depth, sizeof(bmp.color_depth), 1, f_output);
    fwrite(&bmp.compression_method, sizeof(bmp.compression_method), 1, f_output);
    fwrite(&bmp.image_size, sizeof(bmp.image_size), 1, f_output);
    fwrite(&bmp.horizontal_bytes_per_pixel, sizeof(bmp.horizontal_bytes_per_pixel), 1, f_output);
    fwrite(&bmp.vertical_bytes_per_pixel, sizeof(bmp.vertical_bytes_per_pixel), 1, f_output);
    fwrite(&bmp.palette_colors, sizeof(bmp.palette_colors), 1, f_output);
    fwrite(&bmp.important_colors, sizeof(bmp.important_colors), 1, f_output);

    // embed message in image
    bit_to_use = 0;
    j = 0;
    for (i = bmp.offset; i < img_sz; i++) {
        if (j < msg_sz) {
            c = msg_data[j++];
            flag = (byte) c & 0x80;  // get the first bit of c
            flag /= 0x80;
            switch (bit_to_use) {
                case 0:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + flag;
                    break;
                case 1:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 1);
                    break;
                case 2:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 2);
                    break;
                case 3:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 3);
                    break;
                case 4:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 4);
                    break;
                case 5:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 5);
                    break;
                case 6:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 6);
                    break;
                case 7:
                    bmp_data[i] = CLEAR_LSB_1(bmp_data[i]) + (flag << 7);
                    break;
            }

            if (bit_to_use == MAX_LSB - 1) {
                bit_to_use = 0;
            } else {
                bit_to_use++;
            }
        } else {
            break;
        }
    }

    // write modified image data to output file
    fwrite(bmp_data, sizeof(char), img_sz, f_output);

    // close files
    fclose(f_cover);
    fclose(f_text);
    fclose(f_output);

    // free memory
    free(bmp_data);
    free(msg_data);

    return 0;
}

int extract_text(const char *image_file, const char *text_file) {
    FILE *f_image, *f_text;
    BMP bmp;
    byte *bmp_data, *msg_data;
    dword i, j, img_sz, msg_sz;
    int bit_to_use;
    char c;

    // open image file
    f_image = fopen(image_file, "rb");
    if (!f_image) {
        return ENOENT;
    }

    // read image header
    fread(bmp.magic, sizeof(char), 2, f_image);
    fread(&bmp.file_size, sizeof(bmp.file_size), 1, f_image);
    fread(&bmp.reserved_word_1, sizeof(bmp.reserved_word_1), 1, f_image);
    fread(&bmp.reserved_word_2, sizeof(bmp.reserved_word_2), 1, f_image);
    fread(&bmp.offset, sizeof(bmp.offset), 1, f_image);
    fread(&bmp.header_size, sizeof(bmp.header_size), 1, f_image);
    fread(&bmp.image_width, sizeof(bmp.image_width), 1, f_image);
    fread(&bmp.image_height, sizeof(bmp.image_height), 1, f_image);
    fread(&bmp.planes, sizeof(bmp.planes), 1, f_image);
    fread(&bmp.color_depth, sizeof(bmp.color_depth), 1, f_image);
    if (bmp.color_depth != 24) {
        fclose(f_image);
        return ENODEV;
    }
    fread(&bmp.compression_method, sizeof(bmp.compression_method), 1, f_image);
    fread(&bmp.image_size, sizeof(bmp.image_size), 1, f_image);
    fread(&bmp.horizontal_bytes_per_pixel, sizeof(bmp.horizontal_bytes_per_pixel), 1, f_image);
    fread(&bmp.vertical_bytes_per_pixel, sizeof(bmp.vertical_bytes_per_pixel), 1, f_image);
    fread(&bmp.palette_colors, sizeof(bmp.palette_colors), 1, f_image);
    fread(&bmp.important_colors, sizeof(bmp.important_colors), 1, f_image);

    // calculate image size
    img_sz = bmp.image_width * bmp.image_height * 3;

    // allocate memory to store input data
    bmp_data = (byte *) malloc(img_sz);
    if (!bmp_data) {
        fclose(f_image);
        return ENOMEM;
    }

    // read bmp data
    fread(bmp_data, sizeof(char), img_sz, f_image);

    // open output file
    f_text = fopen(text_file, "wb");
    if (!f_text) {
        fclose(f_image);
        free(bmp_data);
        return EACCES;
    }

    // calculate size of message
    msg_sz = 0;
    for (i = bmp.offset; i < img_sz; i++) {
        if (bmp_data[i] & 0x1) {
            msg_sz++;
        }
    }

    // allocate memory to store message data
    msg_data = (byte *) malloc(msg_sz);
    if (!msg_data) {
        fclose(f_image);
        fclose(f_text);
        free(bmp_data);
        return ENOMEM;
    }

    // extract message from image
    bit_to_use = 0;
    j = 0;
    for (i = bmp.offset; i < img_sz; i++) {
        if (j < msg_sz) {
            c = 0;
            switch (bit_to_use) {
                case 0:
                    c |= bmp_data[i] & 0x1;
                    break;
                case 1:
                    c |= (bmp_data[i] & 0x2) >> 1;
                    break;
                case 2:
                    c |= (bmp_data[i] & 0x4) >> 2;
                    break;
                case 3:
                    c |= (bmp_data[i] & 0x8) >> 3;
                    break;
                case 4:
                    c |= (bmp_data[i] & 0x10) >> 4;
                    break;
                case 5:
                    c |= (bmp_data[i] & 0x20) >> 5;
                    break;
                case 6:
                    c |= (bmp_data[i] & 0x40) >> 6;
                    break;
                case 7:
                    c |= (bmp_data[i] & 0x80) >> 7;
                    break;
            }

            if (bit_to_use == MAX_LSB - 1) {
                bit_to_use = 0;
            } else {
                bit_to_use++;
            }

            msg_data[j++] = c;
        } else {
            break;
        }
    }

    // write message to output file
    fwrite(msg_data, sizeof(char), msg_sz, f_text);

    // close files
    fclose(f_image);
    fclose(f_text);

    // free memory
    free(bmp_data);
    free(msg_data);

    return 0;
}

int main(int argc, char **argv) {
    int err;
    if (argc != 4 && argc != 3) {
        printf("Usage: %s embed cover_image message_file [out_image]\n", argv[0]);
        printf("Usage: %s extract image_file message_file\n", argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 4) {
            printf("Usage: %s embed cover_image message_file [out_image]\n", argv[0]);
            return 0;
        }

        err = embed_text(argv[2], argv[3], argc == 4 ? "out.bmp" : argv[4]);
        if (err != 0) {
            printf("Error: %s\n", error_messages[err]);
            return -1;
        }
    } else if (strcmp(argv[1], "extract") == 0) {
        if (argc != 4) {
            printf("Usage: %s extract image_file message_file\n", argv[0]);
            return 0;
        }

        err = extract_text(argv[2], argv[3]);
        if (err != 0) {
            printf("Error: %s\n", error_messages[err]);
            return -1;
        }
    } else {
        printf("Usage: %s embed cover_image message_file [out_image]\n", argv[0]);
        printf("Usage: %s extract image_file message_file\n", argv[0]);
        return 0;
    }

    printf("Operation Successful\n");
    return 0;
}