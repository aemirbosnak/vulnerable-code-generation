//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Initializing global variables*/
int score = 0, randomIndex;
char answer[20];

/*Creating a structure for periodic elements*/
typedef struct Element{
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

/*Storing periodic elements in an array*/
Element elements[118]={
    {"H","Hydrogen",1},
    {"He","Helium",2},
    {"Li","Lithium",3},
    {"Be","Beryllium",4},
    {"B","Boron",5},
    {"C","Carbon",6},
    {"N","Nitrogen",7},
    {"O","Oxygen",8},
    {"F","Fluorine",9},
    {"Ne","Neon",10},
    {"Na","Sodium",11},
    {"Mg","Magnesium",12},
    {"Al","Aluminium",13},
    {"Si","Silicon",14},
    {"P","Phosphorus",15},
    {"S","Sulphur",16},
    {"Cl","Chlorine",17},
    {"Ar","Argon",18},
    {"K","Potassium",19},
    {"Ca","Calcium",20},
    {"Sc","Scandium",21},
    {"Ti","Titanium",22},
    {"V","Vanadium",23},
    {"Cr","Chromium",24},
    {"Mn","Manganese",25},
    {"Fe","Iron",26},
    {"Co","Cobalt",27},
    {"Ni","Nickel",28},
    {"Cu","Copper",29},
    {"Zn","Zinc",30},
    {"Ga","Gallium",31},
    {"Ge","Germanium",32},
    {"As","Arsenic",33},
    {"Se","Selenium",34},
    {"Br","Bromine",35},
    {"Kr","Krypton",36},
    {"Rb","Rubidium",37},
    {"Sr","Strontium",38},
    {"Y","Yttrium",39},
    {"Zr","Zirconium",40},
    {"Nb","Niobium",41},
    {"Mo","Molybdenum",42},
    {"Tc","Technetium",43},
    {"Ru","Ruthenium",44},
    {"Rh","Rhodium",45},
    {"Pd","Palladium",46},
    {"Ag","Silver",47},
    {"Cd","Cadmium",48},
    {"In","Indium",49},
    {"Sn","Tin",50},
    {"Sb","Antimony",51},
    {"Te","Tellurium",52},
    {"I","Iodine",53},
    {"Xe","Xenon",54},
    {"Cs","Cesium",55},
    {"Ba","Barium",56},
    {"La","Lanthanum",57},
    {"Ce","Cerium",58},
    {"Pr","Praseodymium",59},
    {"Nd","Neodymium",60},
    {"Pm","Promethium",61},
    {"Sm","Samarium",62},
    {"Eu","Europium",63},
    {"Gd","Gadolinium",64},
    {"Tb","Terbium",65},
    {"Dy","Dysprosium",66},
    {"Ho","Holmium",67},
    {"Er","Erbium",68},
    {"Tm","Thulium",69},
    {"Yb","Ytterbium",70},
    {"Lu","Lutetium",71},
    {"Hf","Hafnium",72},
    {"Ta","Tantalum",73},
    {"W","Tungsten",74},
    {"Re","Rhenium",75},
    {"Os","Osmium",76},
    {"Ir","Iridium",77},
    {"Pt","Platinum",78},
    {"Au","Gold",79},
    {"Hg","Mercury",80},
    {"Tl","Thallium",81},
    {"Pb","Lead",82},
    {"Bi","Bismuth",83},
    {"Po","Polonium",84},
    {"At","Astatine",85},
    {"Rn","Radon",86},
    {"Fr","Francium",87},
    {"Ra","Radium",88},
    {"Ac","Actinium",89},
    {"Th","Thorium",90},
    {"Pa","Protactinium",91},
    {"U","Uranium",92},
    {"Np","Neptunium",93},
    {"Pu","Plutonium",94},
    {"Am","Americium",95},
    {"Cm","Curium",96},
    {"Bk","Berkelium",97},
    {"Cf","Californium",98},
    {"Es","Einsteinium",99},
    {"Fm","Fermium",100},
    {"Md","Mendelevium",101},
    {"No","Nobelium",102},
    {"Lr","Lawrencium",103},
    {"Rf","Rutherfordium",104},
    {"Db","Dubnium",105},
    {"Sg","Seaborgium",106},
    {"Bh","Bohrium",107},
    {"Hs","Hassium",108},
    {"Mt","Meitnerium",109},
    {"Ds","Darmstadtium",110},
    {"Rg","Roentgenium",111},
    {"Cn","Copernicium",112},
    {"Nh","Nihonium",113},
    {"Fl","Flerovium",114},
    {"Mc","Moscovium",115},
    {"Lv","Livermorium",116},
    {"Ts","Tennessine",117},
    {"Og","Oganesson",118}
};

/*Function to display rules*/
void displayRules(){
    printf("\t\t\tRULES\n");
    printf("1. You will be given an element symbol and you have to guess its name and atomic number.\n");
    printf("2. Each correct answer will get you 2 points.\n");
    printf("3. There is no negative marking for wrong answers.\n");
    printf("4. Press 0 to quit the quiz at any time.\n");
}

/*Function to get the user's answer*/
void getUserAnswer(){
    printf("\nName: ");
    fgets(answer,sizeof(answer),stdin);
    printf("Atomic Number: ");
    fscanf(stdin,"%d",&randomIndex);
}

/*Function to check user's answer*/
void checkUserAnswer(Element element){
    if((strcmp(answer, element.name)==0) && (randomIndex==element.atomicNumber)){
        printf("CORRECT ANSWER! You get 2 points.\n");
        score += 2;
    }
    else if(strcmp(answer, element.name)!=0){
        printf("WRONG ANSWER! Correct name is %s.\n",element.name);
    }
    else{
        printf("WRONG ANSWER! Correct atomic number is %d.\n",element.atomicNumber);
    }
}

/*Function to select a random element*/
Element selectRandomElement(){
    srand(time(0));
    randomIndex = rand()%118;
    return elements[randomIndex];
}

/*Main function*/
int main(){
    Element randomElement;
    int choice;
    
    printf("\t\t\tWELCOME TO THE PERIODIC TABLE QUIZ!\n");
    displayRules();
    
    do{
        randomElement = selectRandomElement();
        printf("\nWhat is the element symbol for %s (enter 0 to quit)?\n",randomElement.name);
        getUserAnswer();
        
        if(randomIndex==0){
            printf("\nGAME OVER!\nYour score: %d",score);
            break;
        }
        
        checkUserAnswer(randomElement);
        
        printf("Your score: %d\n",score);
        printf("Do you want to continue? (Enter 1 to continue or 0 to quit)");
        fscanf(stdin,"%d",&choice);
        fflush(stdin);
        
        if(choice==0){
            printf("\nGAME OVER!\nYour score: %d",score);
            break;
        }
        
    } while(choice!=0);
    return 0;
}