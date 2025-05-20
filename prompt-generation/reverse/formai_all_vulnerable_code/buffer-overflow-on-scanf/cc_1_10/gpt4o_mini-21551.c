//GPT-4o-mini DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void display_message(const char *message) {
    printf("💖 Love's Hidden Message: \"%s\" 💖\n", message);
}

void decode_qr(const char *filename) {
    // This is a placeholder - decoding QR codes requires image processing 
    // which can become complex, hence we assume a QR code is decoded 
    // and presents a love message.
    char *love_message = "You hold the key to my heart!";
    display_message(love_message);
}

void create_qr(const char *message, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(message, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode) {
        FILE *fp = fopen(filename, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Unable to open file to save QR Code.\n");
            return;
        }
        // Saving QR code as a PGM file
        fprintf(fp, "P2\n%d %d\n255\n", qrcode->width, qrcode->width);
        for (int y = 0; y < qrcode->width; y++) {
            for (int x = 0; x < qrcode->width; x++) {
                fputc(qrcode->data[y * qrcode->width + x] & 1 ? '0' : '1', fp);
            }
            fputc('\n', fp);
        }
        fclose(fp);
        QRcode_free(qrcode);
        printf("🌹 A QR code containing your message has been created and saved as: %s 🌹\n", filename);
    } else {
        fprintf(stderr, "Failed to generate QR code.\n");
    }
}

void romantic_interaction() {
    printf("❤️ Welcome to the Realm of Love Codes ❤️\n\n");
    
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Create a QR code with a sweet message.\n");
        printf("2. Decode a QR code to unveil a romantic secret.\n");
        printf("3. Exit this enchanting world.\n");
        printf("Choose an option (1-3): ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char message[256];
            printf("Write your romantic message: ");
            getchar(); // clear newline from buffer
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0'; // Remove newline character

            char filename[256];
            sprintf(filename, "love_qr.png"); // Save as PNG for illustration
            create_qr(message, filename);

        } else if (choice == 2) {
            char filename[256];
            printf("Provide the QR code filename for decoding (it should be a .png or .pgm): ");
            getchar(); // clear newline from buffer
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

            decode_qr(filename);

        } else if (choice == 3) {
            printf("✨ Thank you for visiting this Romantic Realm! Until we meet again! ✨\n");
            break;
        } else {
            printf("🙁 Please choose a valid option (1-3).\n");
        }
        printf("\n");
    }
}

int main() {
    romantic_interaction();
    return 0;
}