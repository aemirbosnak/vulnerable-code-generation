//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

void error_exit(j_common_ptr cinfo) {
    (*cinfo->err->output_message)(cinfo);
    exit(1);
}

void decode_JPEG(const char *filename, unsigned char **image_buffer, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening JPEG file %s\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jerr.error_exit = error_exit;

    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int pixel_size = cinfo.output_components;

    *image_buffer = (unsigned char *)malloc(*width * *height * pixel_size);
    unsigned char *row_pointer[1];

    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = *image_buffer + cinfo.output_scanline * (*width * pixel_size);
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void encode_JPEG(const char *filename, unsigned char *image_buffer, int width, int height, int quality) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *outfile = fopen(filename, "wb");
    if (!outfile) {
        fprintf(stderr, "Error opening output JPEG file %s\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // assuming RGB
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE);
    jpeg_start_compress(&cinfo, TRUE);

    unsigned char *row_pointer[1];
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] = image_buffer + cinfo.next_scanline * (width * cinfo.input_components);
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

void invert_colors(unsigned char *image_buffer, int width, int height) {
    int num_pixels = width * height * 3; // Assuming RGB format
    for (int i = 0; i < num_pixels; i++) {
        image_buffer[i] = 255 - image_buffer[i];
    }
}

void print_usage(char *prog_name) {
    fprintf(stdout, "Usage: %s <input.jpg> <output.jpg> <quality>\n", prog_name);
    fprintf(stdout, "       Qualities from 0 to 100 (100 being the best quality)\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    unsigned char *image_buffer;
    int width, height;
    int quality = atoi(argv[3]);

    decode_JPEG(argv[1], &image_buffer, &width, &height);
    printf("Image %s loaded: %d x %d\n", argv[1], width, height);

    invert_colors(image_buffer, width, height);
    printf("Colors inverted!\n");

    encode_JPEG(argv[2], image_buffer, width, height, quality);
    printf("Image saved as %s with quality %d\n", argv[2], quality);

    free(image_buffer);
    return 0;
}