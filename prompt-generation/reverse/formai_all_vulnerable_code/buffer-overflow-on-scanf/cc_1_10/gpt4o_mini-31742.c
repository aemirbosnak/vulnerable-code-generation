//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 7

void encrypt_file(const char *file_name);
void decrypt_file(const char *file_name);
void display_menu();
void execute_choice(int choice);

int main() {
    int choice;
    
    display_menu();
    
    printf("Pray tell, noble scribe, enter thy choice: ");
    scanf("%d", &choice);
    
    while (choice < 1 || choice > 3) {
        printf("Alas! Choose wisely: ");
        scanf("%d", &choice);
    }
    
    execute_choice(choice);
    
    return 0;
}

void display_menu() {
    printf("\n*** Enchanter's File Encryptor ***\n");
    printf("1. Encrypt a Scroll\n");
    printf("2. Decrypt a Scroll\n");
    printf("3. Exit the Realm\n");
    printf("*********************************\n");
}

void execute_choice(int choice) {
    char file_name[256];
    
    if (choice == 1) {
        printf("State the name of the scroll thou wishest to encrypt: ");
        scanf("%s", file_name);
        encrypt_file(file_name);
    } else if (choice == 2) {
        printf("State the name of the scroll thou wishest to decrypt: ");
        scanf("%s", file_name);
        decrypt_file(file_name);
    } else {
        printf("Fare thee well, noble soul! The realm awaits thee!\n");
        exit(0);
    }
}

void encrypt_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Alas! The scroll could not be found.\n");
        return;
    }
    
    FILE *encrypted_file = fopen("encrypted_scroll.txt", "w");
    if (!encrypted_file) {
        printf("An error hath befallen during the creation of the encrypted scroll.\n");
        fclose(file);
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = ch + KEY;
        fputc(ch, encrypted_file);
    }
    
    printf("The scroll hath been successfully encrypted! 'encrypted_scroll.txt' is ready.\n");
    
    fclose(file);
    fclose(encrypted_file);
}

void decrypt_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Alas! The scroll could not be found.\n");
        return;
    }

    FILE *decrypted_file = fopen("decrypted_scroll.txt", "w");
    if (!decrypted_file) {
        printf("An error hath befallen during the creation of the decrypted scroll.\n");
        fclose(file);
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = ch - KEY;
        fputc(ch, decrypted_file);
    }

    printf("The scroll hath been successfully decrypted! 'decrypted_scroll.txt' is ready.\n");
    
    fclose(file);
    fclose(decrypted_file);
}