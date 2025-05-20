//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <string.h>

void print_metadata(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile;
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open %s\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);

    // Read header
    jpeg_read_header(&cinfo, TRUE);
    
    printf("------------------------------------------------------\n");
    printf("Metadata for %s:\n", filename);
    printf("Width: %d pixels\n", cinfo.image_width);
    printf("Height: %d pixels\n", cinfo.image_height);
    printf("Color Components: %d\n", cinfo.num_components);
    
    // Calculate color depth
    int color_depth = cinfo.num_components * 8; // 8 bits per component
    printf("Color Depth: %d bits\n", color_depth);
    printf("------------------------------------------------------\n");

    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image1.jpg> <image2.jpg> ... <imageN.jpg>\n", argv[0]);
        return 1;
    }

    printf("Welcome to the JPEG Metadata Extractor!\n");
    printf("You provided %d image files:\n", argc - 1);
    
    for (int i = 1; i < argc; i++) {
        printf("Processing file: %s\n", argv[i]);
        print_metadata(argv[i]);
    }

    printf("All files processed! Exiting program... Bye!\n");
    return 0;
}