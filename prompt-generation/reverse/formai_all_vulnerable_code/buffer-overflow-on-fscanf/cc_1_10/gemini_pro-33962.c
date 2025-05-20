//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE "reader.conf"

// Configuration options
typedef struct {
    int font_size;
    int line_spacing;
    char *font_family;
    char *background_color;
    char *text_color;
} config_t;

// Load configuration from file
config_t load_config(const char *filename) {
    config_t config;
    FILE *fp;

    // Open configuration file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening configuration file\n");
        exit(1);
    }

    // Read configuration options
    fscanf(fp, "font_size=%d\n", &config.font_size);
    fscanf(fp, "line_spacing=%d\n", &config.line_spacing);
    fscanf(fp, "font_family=%s\n", config.font_family);
    fscanf(fp, "background_color=%s\n", config.background_color);
    fscanf(fp, "text_color=%s\n", config.text_color);

    // Close configuration file
    fclose(fp);

    return config;
}

// Display ebook
void display_ebook(const char *filename, config_t config) {
    FILE *fp;
    char line[1024];

    // Open ebook file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening ebook file\n");
        exit(1);
    }

    // Set up display configuration
    printf("\n");
    printf("<style>\n");
    printf("body {\n");
    printf("  font-size: %dpx;\n", config.font_size);
    printf("  line-height: %dpx;\n", config.line_spacing);
    printf("  font-family: %s;\n", config.font_family);
    printf("  background-color: %s;\n", config.background_color);
    printf("  color: %s;\n", config.text_color);
    printf("}\n");
    printf("</style>\n");

    // Read ebook file and display text
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    // Close ebook file
    fclose(fp);
}

int main(int argc, char **argv) {
    config_t config;

    // Load configuration file
    config = load_config(CONFIG_FILE);

    // Display ebook
    display_ebook(argv[1], config);

    return 0;
}