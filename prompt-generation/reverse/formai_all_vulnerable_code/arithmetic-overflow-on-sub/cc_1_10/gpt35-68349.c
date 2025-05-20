//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>

// Morse Code mapping table
const char* CODE[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                      ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                      "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int main(int argc, char *argv[]) {
    // Check if input argument is provided
    if(argc < 2) {
        printf("Please provide a string input\n");
        return 1;
    }
    // Open /dev/mem for memory mapping
    int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
    // Check if memory file opened successfully
    if(mem_fd == -1) {
        printf("Error: Could not open /dev/mem\n");
        return 1;
    }
    
    // Get the physical address of GPIO controller
    unsigned int GPIO_BASE = 0x3F200000;
    unsigned int GPIO_LEN = 0x1000;
    unsigned int GPIO_INDEX = 7;
    unsigned int PERIPH_PHYS_OFFSET = GPIO_BASE + GPIO_INDEX*4;
    unsigned int PERIPH_MAP_LEN = 0x1000;
    off_t PERIPH_OFFSET = PERIPH_PHYS_OFFSET & ~(sysconf(_SC_PAGE_SIZE) - 1);
    size_t PERIPH_MAP_SIZE = PERIPH_MAP_LEN + (PERIPH_PHYS_OFFSET - PERIPH_OFFSET);
    unsigned char* PERIPH_MAP = mmap(NULL, PERIPH_MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, PERIPH_OFFSET);
    // Check if memory mapping was successful
    if(PERIPH_MAP == (void *) -1) {
        printf("Error: Could not map peripheral memory\n");
        return 1;
    }
    
    // Set the direction of GPIO pin as output
    unsigned int pysical_address = GPIO_BASE + 0x04 * GPIO_INDEX;
    unsigned int gpio_bits_on = 1 << 25; // Set bit 25 to 1
    unsigned int gpio_bits_off = 1 << 25; // Set bit 25 to 0
    *((unsigned int*) PERIPH_MAP + pysical_address/4) = gpio_bits_on; // Set pin 25 as output
    sleep(1); // Sleep for 1 second
    
    // Loop through each character in the input string
    for(int i=0; i<strlen(argv[1]); i++) {
        char c = toupper(argv[1][i]); // Convert character to uppercase
        if(c < 'A' || c > 'Z') continue; // Ignore non-English alphabets
        int idx = c - 'A'; // Get the Morse code mapping of the character
        const char* morse = CODE[idx];
        
        // Flip the LED on and off based on the Morse code mapping
        for(int j=0; j<strlen(morse); j++) {
            if(morse[j] == '.') {
                *((unsigned int*) PERIPH_MAP + pysical_address/4) = gpio_bits_on; // LED ON
                sleep(1); // Sleep for 1 second
                *((unsigned int*) PERIPH_MAP + pysical_address/4) = gpio_bits_off; // LED OFF
            }
            else if(morse[j] == '-') {
                *((unsigned int*) PERIPH_MAP + pysical_address/4) = gpio_bits_on; // LED ON
                sleep(3); // Sleep for 3 second
                *((unsigned int*) PERIPH_MAP + pysical_address/4) = gpio_bits_off; // LED OFF
            }
            sleep(1); // Sleep for 1 second before processing the next Morse code
        }
        sleep(2); // Sleep for 2 seconds before processing the next character
    }
    
    // Unmap the memory and close the file descriptor
    munmap(PERIPH_MAP, PERIPH_MAP_SIZE);
    close(mem_fd);
    return 0;
}