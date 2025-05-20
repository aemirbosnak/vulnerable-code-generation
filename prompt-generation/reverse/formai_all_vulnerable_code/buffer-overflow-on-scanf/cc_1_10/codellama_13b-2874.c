//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
int main() {
    // Define variables
    int choice;
    char name[20];
    int age;
    char gender;
    float height, weight;
    char medicine[50];
    int dosage;
    int prescription;
    char doctor[50];
    int patient_id;

    // Print welcome message
    printf("Welcome to the Medical Store Management System!\n");

    // Get patient details
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);
    printf("Enter your height (in inches): ");
    scanf("%f", &height);
    printf("Enter your weight (in pounds): ");
    scanf("%f", &weight);

    // Get medicine details
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine);
    printf("Enter the dosage: ");
    scanf("%d", &dosage);
    printf("Enter the prescription number: ");
    scanf("%d", &prescription);
    printf("Enter the name of the doctor: ");
    scanf("%s", doctor);
    printf("Enter the patient ID: ");
    scanf("%d", &patient_id);

    // Print patient details
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Height: %f inches\n", height);
    printf("Weight: %f pounds\n", weight);
    printf("Medicine: %s\n", medicine);
    printf("Dosage: %d\n", dosage);
    printf("Prescription: %d\n", prescription);
    printf("Doctor: %s\n", doctor);
    printf("Patient ID: %d\n", patient_id);

    return 0;
}