#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char header[4];
    unsigned int length;
    unsigned char data[BUFFER_SIZE];
} AudioPacket;

void read_audio_packet(FILE* file, AudioPacket* packet) {
    fread(packet->header, sizeof(unsigned char), 4, file);
    fread(&(packet->length), sizeof(unsigned int), 1, file);
    fread(packet->data, sizeof(unsigned char), packet->length, file);
}

void write_audio_packet(FILE* file, AudioPacket* packet) {
    fwrite(packet->header, sizeof(unsigned char), 4, file);
    fwrite(&(packet->length), sizeof(unsigned int), 1, file);
    fwrite(packet->data, sizeof(unsigned char), packet->length, file);
}

void decode_audio(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");
    AudioPacket packet;
    unsigned char extra_data[BUFFER_SIZE];

    while (fgetc(input) != EOF) {
        read_audio_packet(input, &packet);

        // Here's the out-of-bounds write
        memcpy(packet.data + packet.length, extra_data, sizeof(extra_data));

        write_audio_packet(output, &packet);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    decode_audio(argv[1], argv[2]);

    return 0;
}
