//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int MAX_COLOR_STR_LEN = 20;

typedef enum color_format_t {
    COLOR_RGB = 0,
    COLOR_HEX = 1,
    COLOR_INVALID = 2
} color_format_t;

typedef struct color_t {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color_t;

typedef struct color_converter_t {
    color_format_t input_format;
    color_format_t output_format;
    void (*convert)(const void *input, void *output);
} color_converter_t;

const unsigned char MAX_HEX_CHAR = '9';
const unsigned char MIN_HEX_CHAR = '0';
const unsigned char HEX_CHAR_OFFSET = 39;
const unsigned char HEX_CHAR_BIT_MASK = 0b00001111;
const unsigned char NUM_HEX_CHARS = 6;
const unsigned char BIT_SHIFT_PER_CHAR = 4;

color_format_t get_color_format(const char *color_str);
int convert_rgb_to_hex(const color_t *rgb, char *hex);
int convert_hex_to_rgb(const char *hex, color_t *rgb);
void print_error(const char *message);
void print_usage();
color_converter_t get_color_converter(color_format_t input_format, color_format_t output_format);
int convert_color(const color_converter_t *converter, const void *input, void *output);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        print_usage();
        exit(1);
    }

    color_converter_t converter = get_color_converter(get_color_format(argv[1]), get_color_format(argv[2]));

    if (converter.input_format == COLOR_INVALID || converter.output_format == COLOR_INVALID) {
        print_usage();
        exit(1);
    }

    if (converter.input_format == COLOR_RGB) {
        color_t rgb;
        if (sscanf(argv[1], "%hhu,%hhu,%hhu", &rgb.red, &rgb.green, &rgb.blue) != 3) {
            print_error("Invalid RGB color format. Please use the following syntax: \"red,green,blue\" where each value is a number between 0 and 255.");
            exit(1);
        }
        char hex[NUM_HEX_CHARS + 1];
        if (convert_color(&converter, &rgb, hex)) {
            printf("%s\n", hex);
        }
    } else if (converter.input_format == COLOR_HEX) {
        color_t rgb;
        if (strlen(argv[1]) != NUM_HEX_CHARS || convert_color(&converter, argv[1], &rgb)) {
            printf("#%02x%02x%02x\n", rgb.red, rgb.green, rgb.blue);
        }
    }

    return 0;
}

color_format_t get_color_format(const char *color_str)
{
    if (color_str[0] == '#') {
        return COLOR_HEX;
    } else if (strchr(color_str, ',') != NULL) {
        return COLOR_RGB;
    } else {
        return COLOR_INVALID;
    }
}

int convert_rgb_to_hex(const color_t *rgb, char *hex)
{
    for (unsigned int i = 0; i < NUM_HEX_CHARS; i += 2) {
        unsigned char value = rgb->red >> BIT_SHIFT_PER_CHAR * i;
        hex[i] = value > MIN_HEX_CHAR ? (value + HEX_CHAR_OFFSET) : value + '0';
        value = rgb->green >> BIT_SHIFT_PER_CHAR * i;
        hex[i + 1] = value > MIN_HEX_CHAR ? (value + HEX_CHAR_OFFSET) : value + '0';
    }
    hex[NUM_HEX_CHARS] = '\0';
    return 0;
}

int convert_hex_to_rgb(const char *hex, color_t *rgb)
{
    unsigned int hex_value;
    int success = 0;
    unsigned int i;
    for (i = 0; i < NUM_HEX_CHARS; i++) {
        hex_value = hex[i];
        if (hex_value > MAX_HEX_CHAR) {
            hex_value -= HEX_CHAR_OFFSET;
        }
        hex_value &= HEX_CHAR_BIT_MASK;
        success |= hex_value;
    }
    if (success) {
        for (i = 0; i < NUM_HEX_CHARS; i += 2) {
            hex_value = hex[i + 1];
            if (hex_value > MAX_HEX_CHAR) {
                hex_value -= HEX_CHAR_OFFSET;
            }
            hex_value &= HEX_CHAR_BIT_MASK;
            hex_value <<= BIT_SHIFT_PER_CHAR * i;
            rgb->green |= hex_value;
            hex_value = hex[i];
            if (hex_value > MAX_HEX_CHAR) {
                hex_value -= HEX_CHAR_OFFSET;
            }
            hex_value &= HEX_CHAR_BIT_MASK;
            hex_value <<= BIT_SHIFT_PER_CHAR * i;
            rgb->red |= hex_value;
        }
    }
    return success;
}

void print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
}

void print_usage()
{
    printf("Usage:\n");
    printf("color_converter <input_color> <output_color>\n");
    printf("Where input_color and output_color are in one of the following formats:\n");
    printf("- RGB: \"red,green,blue\" where each value is a number between 0 and 255\n");
    printf("- HEX: \"#rrggbb\" where each character is a hexadecimal digit\n");
    printf("Example:\n");
    printf("color_converter \"255,0,0\" \"#ffffff\"\n");
}

color_converter_t get_color_converter(color_format_t input_format, color_format_t output_format)
{
    color_converter_t converter;
    converter.input_format = input_format;
    converter.output_format = output_format;
    switch (input_format) {
    case COLOR_RGB:
        switch (output_format) {
        case COLOR_HEX:
            converter.convert = convert_rgb_to_hex;
            break;
        default:
            converter.convert = NULL;
        }
        break;
    case COLOR_HEX:
        switch (output_format) {
        case COLOR_RGB:
            converter.convert = convert_hex_to_rgb;
            break;
        default:
            converter.convert = NULL;
        }
        break;
    default:
        converter.convert = NULL;
    }
    return converter;
}

int convert_color(const color_converter_t *converter, const void *input, void *output)
{
    if (converter->convert == NULL) {
        return -1;
    }
    converter->convert(input, output);
    return 0;
}