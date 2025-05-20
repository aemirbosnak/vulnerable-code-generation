//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

uchar* load_image(char* filename)
{
    FILE* fp = fopen(filename, "rb");
    if (!fp)
        return NULL;
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    uchar* data = malloc(size);
    if (!data)
        return NULL;
    
    fread(data, 1, size, fp);
    fclose(fp);
    
    return data;
}

void save_image(char* filename, uchar* data, int width, int height)
{
    FILE* fp = fopen(filename, "wb");
    if (!fp)
        return;
    
    fwrite(data, width * height, 1, fp);
    fclose(fp);
}

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        printf("Usage: %s <input> <output> <command>\n", argv[0]);
        return 1;
    }
    
    uchar* data = load_image(argv[1]);
    if (!data)
    {
        printf("Error loading image\n");
        return 1;
    }
    
    int width = 0, height = 0;
    int* widths = malloc(argc * sizeof(int));
    int* heights = malloc(argc * sizeof(int));
    
    for (int i = 1; i < argc; i++)
    {
        sscanf(argv[i], "%dx%d", &widths[i - 1], &heights[i - 1]);
        width += widths[i - 1];
        height = height > heights[i - 1] ? height : heights[i - 1];
    }
    
    uchar* output = malloc(width * height);
    if (!output)
    {
        printf("Error allocating memory\n");
        return 1;
    }
    
    int offset = 0;
    
    for (int i = 1; i < argc; i++)
    {
        uchar* img = load_image(argv[i]);
        if (!img)
        {
            printf("Error loading image\n");
            return 1;
        }
        
        memcpy(output + offset, img, widths[i - 1] * heights[i - 1]);
        offset += widths[i - 1] * heights[i - 1];
        
        free(img);
    }
    
    save_image(argv[2], output, width, height);
    
    free(data);
    free(output);
    free(widths);
    free(heights);
    
    return 0;
}